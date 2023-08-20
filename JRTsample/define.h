#include <stdint.h>
#ifndef _INIT_H_
#define _INIT_H_

#define LED1  38
#define LED2  39
#define LED3  40
#define LED4  41
#define LED5  42
#define LED6  43
#define LED7  44
#define LED8  45
#define LED9  46
#define LED10 47
#define LED11 48
#define LED12 49
#define LED13 50  //MISO
#define LED14 51  //MOSI
#define LED15 52  //SCK
#define LED16 53

#define SW1   22
#define SW2   23
#define SW3   24
#define SW4   25
#define SW5   26
#define SW6   27
#define SW7   28
#define SW8   29
#define SW9   30
#define SW10  31
#define SW11  32
#define SW12  33
#define SW13  34
#define SW14  35
#define SW15  36
#define SW16  37

#define BUZZER  10

#define MOTOR1  9
#define MOTOR2  8
#define MOTOR3  7
#define MOTOR4  6
#define MOTOR5  5
#define MOTOR6  4
#define MOTOR7  3
#define MOTOR8  2

#define DIR1  54
#define DIR2  55
#define DIR3  56
#define DIR4  57
#define DIR5  58
#define DIR6  59
#define DIR7  60
#define DIR8  61

#define SERVO1 13
#define SERVO2 12
#define SERVO3 11

#define AF1 62
#define AF2 63

#define RMmotorNUM 8

/********  制御周期  ********/
const uint8_t period = 1;    // 制御周期
uint64_t StartTime = 0;       // 周期固定用　開始時間


/********  コントローラ  ********/
int RxData[4] = {};   //受信したデータをセミコロン毎に分割
uint64_t GetTime_Controller = 0;  //タイムアウト用で使用予定
int16_t OperationEnable = 1;      //操作禁止orオートレフェリでON

/********  オートレフェリ  ********/
#define AF_Signal1 digitalRead(AF1)  //押出の前側のリミット

/********  射出  ********/
#define SHOT_FRONT_SW digitalRead(SW1)  //押出の前側のリミット
#define SHOT_BACK_SW digitalRead(SW2)   //押出の後側のリミット
uint8_t ShotSeq = 0;      //押して戻るときのシーケンスカウント用
uint8_t RollerSeq = 0;    //えいやーでチャタリング＆連打対策してるけど，あとでちゃんとしたい
uint8_t RollerOnOff = 0;  //ON/OFFの切り替え記憶用

/********  RMモータ制御に関する構造体  ********/
typedef struct RMmotor {

  // 送信するデータ
  int32_t TxVel; //速度[rpm]
  int32_t TxAmp; //電流[mA]

  // 受信するデータ
  int32_t RxVel; //速度[rpm]
  int32_t RxAmp; //電流[mA]
} RMmotor;
RMmotor motor[RMmotorNUM] = {};  // 各モータのデータ
uint16_t LimitAmp[RMmotorNUM] = {0, 5000}; //電流の制限

const uint8_t ROLLER = 1;

/********  CAN  ********/
struct can_frame MotorTxData; // CANでモータに送信するデータ
struct can_frame MotorRxData; // CANでモータから受信するデータ

/********  PID  ********/
float RollerP = 0.35;    // ローラ用のPゲイン
float RollerI = 0.0;     // ローラ用のIゲイン
float RollerD = 0.1;     // ローラ用のDゲイン

float PIDdiff[RMmotorNUM] = {};  // D制御用の過去の誤差量

#endif