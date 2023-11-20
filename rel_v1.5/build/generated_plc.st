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
    pwr_plant_switch AT %QX99.5 : BOOL;
  END_VAR
  VAR
    pwr_plant : BOOL;
  END_VAR
  VAR
    pwr_gen AT %QX0.0 : BOOL;
    pwr_buildings_on AT %QX0.1 : BOOL;
    pwr_buildings_off AT %QX0.2 : BOOL;
    pwr_hospital_on AT %QX0.3 : BOOL;
    pwr_hospital_off AT %QX0.4 : BOOL;
    alarm AT %QX0.5 : BOOL;
    antenna AT %QX0.6 : BOOL;
  END_VAR
  VAR
    alarm_start : BOOL;
    alarm_reset : BOOL;
    TP_WITH_RESET0 : TP_WITH_RESET;
    TP0 : TP;
  END_VAR
  VAR
    input_value_gen AT %QW0 : INT := 5000;
    input_value_pwr AT %QW1 : INT := 7000;
    threshold_min_gen AT %QW2 : INT := 2000;
    threshold_min_pwr AT %QW3 : INT := 5000;
  END_VAR
  VAR
    threshold_min_output_gen : BOOL;
    threshold_min_output_pwr : BOOL;
    CTU0 : CTU;
    temp_up : BOOL;
    temp_down : BOOL;
    max_temp : INT := 21;
  END_VAR
  VAR
    current_temp AT %QW4 : INT;
  END_VAR
  VAR
    temp_pulse : BOOL;
    TP2 : TP;
    TP_WITH_RESET1 : TP_WITH_RESET;
    temp_threshold : INT := 6;
  END_VAR
  VAR
    temp_alarm AT %QX99.4 : BOOL;
    max_temp_alarm AT %QX99.7 : BOOL;
    gen_full AT %QW6 : INT := 100;
    fuel_value AT %QW5 : INT;
  END_VAR
  VAR
    gen_empty : BOOL;
    gen_empty_pulse : BOOL;
    CTD0 : CTD;
    TP1 : TP;
    TP3 : TP;
  END_VAR
  VAR
    fuel_reset AT %QX99.6 : BOOL;
  END_VAR
  VAR
    max_pwr_plant : INT := 9000;
  END_VAR
  VAR
    vape_smoke AT %QX0.7 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    pwr_plant_broke : BOOL;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    _TMP_GT5_OUT : BOOL;
    _TMP_GT92_OUT : BOOL;
    _TMP_GT12_OUT : BOOL;
    _TMP_GT22_OUT : BOOL;
  END_VAR

  pwr_plant := NOT(pwr_plant_broke) AND threshold_min_output_pwr AND NOT(pwr_plant_switch);
  pwr_gen := NOT(gen_empty) AND threshold_min_output_gen AND NOT(pwr_plant);
  pwr_buildings_on := pwr_plant;
  antenna := pwr_plant;
  pwr_buildings_off := NOT(pwr_plant);
  alarm_start := NOT(pwr_plant);
  TP_WITH_RESET0(IN := NOT(alarm_reset) AND (alarm_start OR pwr_gen), PT := T#2s);
  alarm := TP_WITH_RESET0.Q;
  TP0(IN := TP_WITH_RESET0.Q, PT := T#4s);
  alarm_reset := TP0.Q;
  pwr_hospital_on := pwr_gen OR pwr_plant;
  pwr_hospital_off := NOT(pwr_plant) AND NOT(pwr_gen);
  temp_up := NOT(pwr_plant) AND NOT(pwr_gen);
  TP_WITH_RESET1(IN := NOT(temp_pulse) AND temp_up, PT := T#1s);
  TP2(IN := TP_WITH_RESET1.Q, PT := T#2s);
  temp_pulse := TP2.Q;
  R_TRIG1(CLK := TP2.Q);
  CTU0(CU := R_TRIG1.Q, R := pwr_hospital_on, PV := max_temp);
  max_temp_alarm := CTU0.Q;
  current_temp := CTU0.CV;
  fuel_reset := TRUE;
  TP1(IN := NOT(gen_empty_pulse) AND pwr_gen, PT := T#2s);
  R_TRIG2(CLK := TP1.Q);
  TP3(IN := fuel_reset, PT := T#1s);
  CTD0(CD := R_TRIG2.Q, LD := TP3.Q, PV := gen_full);
  gen_empty := CTD0.Q;
  gen_empty_pulse := TP1.Q;
  fuel_value := CTD0.CV;
  _TMP_GT5_OUT := GT(input_value_pwr, threshold_min_pwr);
  threshold_min_output_pwr := _TMP_GT5_OUT;
  _TMP_GT92_OUT := GT(input_value_pwr, max_pwr_plant);
  vape_smoke := NOT(pwr_plant_broke) AND pwr_plant AND _TMP_GT92_OUT;
  TON0(IN := NOT(pwr_plant_broke) AND pwr_plant AND _TMP_GT92_OUT, PT := T#60s);
  pwr_plant_broke := TON0.Q OR pwr_plant_broke;
  _TMP_GT12_OUT := GT(input_value_gen, threshold_min_gen);
  threshold_min_output_gen := _TMP_GT12_OUT;
  _TMP_GT22_OUT := GT(current_temp, temp_threshold);
  temp_alarm := _TMP_GT22_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : aplha;
  END_RESOURCE
END_CONFIGURATION
