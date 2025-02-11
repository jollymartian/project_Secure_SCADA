void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void TP_WITH_RESET_init__(TP_WITH_RESET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->PREV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CURRENT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TP_WITH_RESET_body__(TP_WITH_RESET *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
__SET_VAR(data__->,CURRENT_TIME,,__CURRENT_TIME)
  #undef GetFbVar
  #undef SetFbVar
;
  if ((((__GET_VAR(data__->STATE,) == 0) && !(__GET_VAR(data__->PREV_IN,))) && __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START_TIME,,__GET_VAR(data__->CURRENT_TIME,));
  } else if ((__GET_VAR(data__->STATE,) == 1)) {
    if (LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_add(__GET_VAR(data__->START_TIME,), __GET_VAR(data__->PT,)), __GET_VAR(data__->CURRENT_TIME,))) {
      __SET_VAR(data__->,STATE,,2);
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ET,,__GET_VAR(data__->PT,));
    } else {
      __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->CURRENT_TIME,), __GET_VAR(data__->START_TIME,)));
    };
  };
  if (((__GET_VAR(data__->STATE,) == 2) && !(__GET_VAR(data__->IN,)))) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,0);
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STATE,,0);
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,PREV_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_WITH_RESET_body__() 





void APLHA_init__(APLHA *data__, BOOL retain) {
  __INIT_VAR(data__->PWR_PLANT_SWITCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_PLANT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_GEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_BUILDINGS_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_BUILDINGS_OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_HOSPITAL_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PWR_HOSPITAL_OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_RESET,__BOOL_LITERAL(FALSE),retain)
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET0,retain);
  TP_init__(&data__->TP0,retain);
  __INIT_VAR(data__->INPUT_VALUE_GEN,5000,retain)
  __INIT_VAR(data__->INPUT_VALUE_PWR,7000,retain)
  __INIT_VAR(data__->THRESHOLD_MIN_GEN,2000,retain)
  __INIT_VAR(data__->THRESHOLD_MIN_PWR,5000,retain)
  __INIT_VAR(data__->THRESHOLD_MIN_OUTPUT_GEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->THRESHOLD_MIN_OUTPUT_PWR,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->TEMP_UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP_DOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAX_TEMP,21,retain)
  __INIT_VAR(data__->CURRENT_TEMP,0,retain)
  __INIT_VAR(data__->TEMP_PULSE,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TP2,retain);
  TP_WITH_RESET_init__(&data__->TP_WITH_RESET1,retain);
  __INIT_VAR(data__->TEMP_THRESHOLD,6,retain)
  __INIT_VAR(data__->TEMP_ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAX_TEMP_ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GEN_FULL,100,retain)
  __INIT_VAR(data__->FUEL_VALUE,0,retain)
  __INIT_VAR(data__->GEN_EMPTY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GEN_EMPTY_PULSE,__BOOL_LITERAL(FALSE),retain)
  CTD_init__(&data__->CTD0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP3,retain);
  __INIT_VAR(data__->FUEL_RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAX_PWR_PLANT,9000,retain)
  __INIT_VAR(data__->VAPE_SMOKE,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->PWR_PLANT_BROKE,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_GT5_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT92_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT22_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void APLHA_body__(APLHA *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,PWR_PLANT,,((!(__GET_VAR(data__->PWR_PLANT_BROKE,)) && __GET_VAR(data__->THRESHOLD_MIN_OUTPUT_PWR,)) && !(__GET_VAR(data__->PWR_PLANT_SWITCH,))));
  __SET_VAR(data__->,PWR_GEN,,((!(__GET_VAR(data__->GEN_EMPTY,)) && __GET_VAR(data__->THRESHOLD_MIN_OUTPUT_GEN,)) && !(__GET_VAR(data__->PWR_PLANT,))));
  __SET_VAR(data__->,PWR_BUILDINGS_ON,,__GET_VAR(data__->PWR_PLANT,));
  __SET_VAR(data__->,PWR_BUILDINGS_OFF,,!(__GET_VAR(data__->PWR_PLANT,)));
  __SET_VAR(data__->,ALARM_START,,!(__GET_VAR(data__->PWR_PLANT,)));
  __SET_VAR(data__->TP_WITH_RESET0.,IN,,(!(__GET_VAR(data__->ALARM_RESET,)) && (__GET_VAR(data__->ALARM_START,) || __GET_VAR(data__->PWR_GEN,))));
  __SET_VAR(data__->TP_WITH_RESET0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET0);
  __SET_VAR(data__->,ALARM,,__GET_VAR(data__->TP_WITH_RESET0.Q,));
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->TP_WITH_RESET0.Q,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 4, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,ALARM_RESET,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->,PWR_HOSPITAL_ON,,(__GET_VAR(data__->PWR_GEN,) || __GET_VAR(data__->PWR_PLANT,)));
  __SET_VAR(data__->,PWR_HOSPITAL_OFF,,(!(__GET_VAR(data__->PWR_PLANT,)) && !(__GET_VAR(data__->PWR_GEN,))));
  __SET_VAR(data__->,TEMP_UP,,(!(__GET_VAR(data__->PWR_PLANT,)) && !(__GET_VAR(data__->PWR_GEN,))));
  __SET_VAR(data__->TP_WITH_RESET1.,IN,,(!(__GET_VAR(data__->TEMP_PULSE,)) && __GET_VAR(data__->TEMP_UP,)));
  __SET_VAR(data__->TP_WITH_RESET1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TP_WITH_RESET_body__(&data__->TP_WITH_RESET1);
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->TP_WITH_RESET1.Q,));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,TEMP_PULSE,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->TP2.Q,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->PWR_HOSPITAL_ON,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->MAX_TEMP,));
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,MAX_TEMP_ALARM,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->,CURRENT_TEMP,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,FUEL_RESET,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TP1.,IN,,(!(__GET_VAR(data__->GEN_EMPTY_PULSE,)) && __GET_VAR(data__->PWR_GEN,)));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->TP1.Q,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->TP3.,IN,,__GET_VAR(data__->FUEL_RESET,));
  __SET_VAR(data__->TP3.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TP_body__(&data__->TP3);
  __SET_VAR(data__->CTD0.,CD,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTD0.,LD,,__GET_VAR(data__->TP3.Q,));
  __SET_VAR(data__->CTD0.,PV,,__GET_VAR(data__->GEN_FULL,));
  CTD_body__(&data__->CTD0);
  __SET_VAR(data__->,GEN_EMPTY,,__GET_VAR(data__->CTD0.Q,));
  __SET_VAR(data__->,GEN_EMPTY_PULSE,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->,FUEL_VALUE,,__GET_VAR(data__->CTD0.CV,));
  __SET_VAR(data__->,_TMP_GT5_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->INPUT_VALUE_PWR,),
    (INT)__GET_VAR(data__->THRESHOLD_MIN_PWR,)));
  __SET_VAR(data__->,THRESHOLD_MIN_OUTPUT_PWR,,__GET_VAR(data__->_TMP_GT5_OUT,));
  __SET_VAR(data__->,_TMP_GT92_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->INPUT_VALUE_PWR,),
    (INT)__GET_VAR(data__->MAX_PWR_PLANT,)));
  __SET_VAR(data__->,VAPE_SMOKE,,((!(__GET_VAR(data__->PWR_PLANT_BROKE,)) && __GET_VAR(data__->PWR_PLANT,)) && __GET_VAR(data__->_TMP_GT92_OUT,)));
  __SET_VAR(data__->TON0.,IN,,((!(__GET_VAR(data__->PWR_PLANT_BROKE,)) && __GET_VAR(data__->PWR_PLANT,)) && __GET_VAR(data__->_TMP_GT92_OUT,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 60, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,PWR_PLANT_BROKE,,(__GET_VAR(data__->TON0.Q,) || __GET_VAR(data__->PWR_PLANT_BROKE,)));
  __SET_VAR(data__->,_TMP_GT12_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->INPUT_VALUE_GEN,),
    (INT)__GET_VAR(data__->THRESHOLD_MIN_GEN,)));
  __SET_VAR(data__->,THRESHOLD_MIN_OUTPUT_GEN,,__GET_VAR(data__->_TMP_GT12_OUT,));
  __SET_VAR(data__->,_TMP_GT22_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENT_TEMP,),
    (INT)__GET_VAR(data__->TEMP_THRESHOLD,)));
  __SET_VAR(data__->,TEMP_ALARM,,__GET_VAR(data__->_TMP_GT22_OUT,));

  goto __end;

__end:
  return;
} // APLHA_body__() 





