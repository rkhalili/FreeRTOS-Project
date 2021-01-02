A task defined in FreeRTOS as below steps: 

*********************************************************************************
/**************** TASK HANDLER *****************/
ex: xTaskHandle vTask1_Handler;

*********************************************************************************
/*************** TASK FUNCTIONS ****************/
ex: void vTask1_Task (void *argument);

*********************************************************************************
 In----------> void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  /****** CREATE TASKS ********/
ex:   xTaskCreate(vTask1_Task, "Task1", 128, NULL, 1, &vTask1_Handler);
	  /**** start the scheduler ****/
ex:   vTaskStartScheduler();
  *******************************************************************************
ex:   void vTask1_Task (void *argument)
ex:    {
ex:	uint32_t TickDelay = pdMS_TO_TICKS(50);
ex:	while (1)
ex:	{
ex:		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
ex:		vTaskDelay(TickDelay);
ex:	}
ex: }