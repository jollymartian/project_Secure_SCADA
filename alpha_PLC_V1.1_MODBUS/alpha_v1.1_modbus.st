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
    pwr_plant AT %QX0.0 : BOOL;
    manual_1 AT %QX0.6 : BOOL;
    manual_2 AT %QX0.7 : BOOL;
    led_green AT %QX0.1 : BOOL;
    led_red AT %QX0.2 : BOOL;
    vape_start AT %QX0.3 : BOOL;
    vape AT %QX0.5 : BOOL;
    vape_reset AT %QX0.4 : BOOL;
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
