#include <Servo.h>
#include <string.h>
#include <SPI.h>
#include <mcp2515.h>
#include "define.h"


MCP2515 mcp2515(20);
Servo roller;


#define WHEEL_L MOTOR1
#define WHEEL_R MOTOR2
#define SHOT MOTOR3
#define PITCH SERVO1

#define SW_ROLLER (RxData[3] & 0b001)
#define SW_SHOT (RxData[3] & 0b010)
#define SW_OTHER (RxData[3] & 0b100)

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);     //PC-Arduino用
  Serial1.begin(115200);    //川村さんコントローラ用
  Serial2.begin(115200);    //オートレフェリ用
  // Serial3.begin(9600);      //予備

  //can-bus 初期化
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  Init();
  InitMotor();
  delay(200);

  BuzzerInitOK();

  Serial.println("Init OK");
}

void loop() {
  // put your main code here, to run repeatedly:
  // 周期固定用に開始時間を取得
  StartTime = millis();

  RxController();

  if((AF_Signal1 == 0) && !SW_OTHER){
    OperationEnable = 1;
  }else{
    OperationEnable = 0;
  }
  

  SensorDebugLED();

  if(OperationEnable){
    Wheel();

    Shot();

    Roller();

    Pitch();

    BuzzerOFF();

  }else{

    RollerOnOff = 0;
    motor[ROLLER].TxVel = 0;
    ShotSeq = 0;

    MotorTxData.can_id  = 0x0200;

    for (int i = 0; i < 8; i++){
      MotorTxData.data[i] = 0;  //モータの指令リセット
      PIDdiff[i] = 0;           //PD制御の誤差をリセット
    }
    mcp2515.sendMessage(&MotorTxData);

    MotorTxData.can_id  = 0x01FF;
    mcp2515.sendMessage(&MotorTxData);

    MotorAllOFF();

    Buzzer1ON();

  }
  

  RMmotorTxData();
  RMmotorRxData();

  //周期固定用の待機(オーバしたら無視)
  while ((millis() - StartTime) < (period) ){
    delayMicroseconds(10);
  }
  
}
