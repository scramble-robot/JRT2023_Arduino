/*
【変数】
RxData[0]~RxData[3]:コントローラから受信したデータが入った配列
  RxData[0]：XXXのアナログ量(-100～100)
  RxData[1]：YYYのアナログ量(-100～100)
  RxData[2]：ピッチのアナログ量(-100～100)
  RxData[3]：スイッチ
ShotSeq：射出のシーケンス管理用変数

【関数】
MotorON(motor, pwm)：モータを回すための関数　motor：回すモータ　pwm：-100~100
  WHEEL_L：左のタイヤ
  WHEEL_R：右のタイヤ
  SHOT：射出用のモータ
  例)　MotorON(WHEEL_L, -50);
MotorOFF(motor)：モータを停止するための関数　motor：停止するモータ

ServoON(servo, angle)：サーボを動かすための関数　servo：動かすサーボ　angle：90~180
  PICTH：ピッチ用のサーボ
  例)　ServoON(PITCH, 100);
  
*/
// 足回りの制御
void Wheel(void){

}

// 射出のシーケンス
void Shot(void){

}

// 射出の角度調整
void Pitch(void){

}