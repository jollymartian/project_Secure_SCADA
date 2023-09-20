TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


FUNCTION_BLOCK TP_WITH_RESET
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
    RESET : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    ET : TIME := T#0s;
  END_VAR
  VAR
    STATE : SINT := 0;
    PREV_IN : BOOL := FALSE;
    CURRENT_TIME : TIME;
    START_TIME : TIME;
  END_VAR

  (* Pragma to set current time *)
  {__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)}

  (*Timer block code *)
  IF ((STATE = 0) AND NOT(PREV_IN) AND IN) THEN  (* found rising edge on IN *)
      (* start timer... *)
      STATE := 1;
      Q := TRUE;
      START_TIME := CURRENT_TIME;

  ELSIF (STATE = 1) THEN (* timer counting *)
      IF ((START_TIME + PT) <= CURRENT_TIME) THEN (* timer expired *)
          STATE := 2;
          Q := FALSE;
          ET := PT;
      ELSE (* continue counting *)
          ET := CURRENT_TIME - START_TIME;
      END_IF;
  END_IF;

  IF ((STATE = 2) AND NOT(IN)) THEN
      ET := T#0s;
      STATE := 0;
  END_IF;

  IF (RESET) THEN (* reset pressed *)
    ET := T#0s;
    STATE := 0;
    Q := FALSE;
  END_IF;

  PREV_IN := IN;
END_FUNCTION_BLOCK

PROGRAM aplha
  VAR
    pwr_plant : BOOL;
    manual_1 : BOOL;
    manual_2 : BOOL;
    led_green : BOOL;
    led_red : BOOL;
    vape_start : BOOL;
    vape : BOOL;
    vape_reset : BOOL;
  END_VAR
  VAR
    TP_WITH_RESET0 : TP_WITH_RESET;
    TP0 : TP;
  END_VAR

  pwr_plant := manual_2 AND (NOT(manual_1) OR pwr_plant);
  led_green := pwr_plant;
  led_red := NOT(pwr_plant);
  vape_start := NOT(pwr_plant);
  TP_WITH_RESET0(IN := NOT(vape_reset) AND vape_start, PT := T#5s);
  vape := TP_WITH_RESET0.Q;
  TP0(IN := TP_WITH_RESET0.Q, PT := T#10s);
  vape_reset := TP0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : aplha;
  END_RESOURCE
END_CONFIGURATION
