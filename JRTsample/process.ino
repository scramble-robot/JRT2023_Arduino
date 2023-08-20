void Wheel(void){
  //不感帯はif文の条件の数値
  //斜め移動のときの横成分を増やしたいときはRxData[0]を割っている4を変える
  //全体の速度を変えたいときは1.3の部分を変える
  //アナログスティック2本になるともっと簡単になる
  if((RxData[1] > 10) ){
    MotorON(WHEEL_L, (int)((-RxData[1] - RxData[0]/4)/1.3));
    MotorON(WHEEL_R, (int)((-RxData[1] + RxData[0]/4)/1.3));
  }else if((RxData[1] < -10) ){
    MotorON(WHEEL_L, (int)((-RxData[1] + RxData[0]/4)/1.3));
    MotorON(WHEEL_R, (int)((-RxData[1] - RxData[0]/4)/1.3));
  }else if(((RxData[1] < 10) && (RxData[1] > -10)) || (RxData[0] > 10) || (RxData[0] < -10)){
    MotorON(WHEEL_L, (int)(-RxData[0]/2));
    MotorON(WHEEL_R, (int)(RxData[0]/2));
  }  else{
    MotorOFF(WHEEL_L);
    MotorOFF(WHEEL_R);
  }
}

void Shot(void){
  //この関数の中を消してJRTで記載してもらうとシーケンス制御のお勉強ができる
  if((RxData[3] & 0b100) && (ShotSeq == 0)){
    MotorON(SHOT, 100);
    ShotSeq = 1;
  }else if((ShotSeq == 1) && (SHOT_FRONT_SW == 0)){
    MotorON(SHOT, -100);
    ShotSeq = 2;
  }else if((ShotSeq == 2) && (SHOT_BACK_SW == 0)){
    MotorOFF(SHOT);
    ShotSeq = 0;
  }
  // Serial.println(ShotSeq);
}

void Roller(void){
  if((RxData[3] & 0b010) && (RollerOnOff == 0) && (RollerSeq == 0)){
    RollerSeq = 1;
    RollerOnOff = 1;
  
    motor[ROLLER].TxVel = 15000;
    delay(100);
  }else if((RxData[3] & 0b010) && (RollerOnOff == 1) && (RollerSeq == 0)){
    RollerSeq = 1;
    RollerOnOff = 0;
  
    motor[ROLLER].TxVel = 0;
    delay(100);
  }

  if((RollerSeq == 1) && ((RxData[3] & 0b010) == 0)){
    RollerSeq = 0;
    delay(100);
  }
}

void Pitch(void){
  //サーボのお勉強がてらここも消すかも
  ServoON(SERVO1, (int)(RxData[2]*90/100 + 90));
}