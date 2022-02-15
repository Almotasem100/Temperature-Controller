in adc .c :

/*Justification for __10.3__ it will read the value from two regesters and ouput it in 1 variable with type u16*/


in DIO.h:
/* defining the registers in this way will violate MISRA rule __11.3__ and will generate many of warning in DIO.c file */


/*breaks MISRA rule __1.1__
(MISRA rules require that you build in strict ANSI mode.
This means it is an error to use any feature not specified in the ANSI standard.
In your case, these features are the keywords cregister and interrupt.
The net effect is you cannot use interrupt and cregister and, at the same time, conform to MISRA.)*/


in LCD /*Justification for __17.4__ the index will never exceed our predected range*/