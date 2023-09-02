void Wheel(void){
  //不感帯はif文の条件の数値
  //斜め移動のときの横成分を増やしたいときはRxData[0]を割っている4を変える
  //全体の速度を変えたいときは1.3の部分を変える
  //アナログスティック2本になるともっと簡単になる

  //右タイヤ
  if((RxData[0] > 10) || (RxData[0] < -10)){
    MotorON(WHEEL_R, RxData[0]);
  }else{
    MotorOFF(WHEEL_R);
  }

  //左タイヤ
  if((RxData[1] > 10) || (RxData[1] < -10)){
    MotorON(WHEEL_L, RxData[1]);
  }else{
    MotorOFF(WHEEL_L);
  }

}

void Shot(void){
  //この関数の中を消してJRTで記載してもらうとシーケンス制御のお勉強ができる
  if(SW_SHOT && (ShotSeq == 0)){
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
  if(SW_ROLLER && ((millis() - RollerTime) > 500)){ //押した検出　チャタリング防止で500ms間は連打できない
    RollerSeq = 1;
    RollerTime = millis();  //チャタリング用
    delay(50);
  }else if((!SW_ROLLER) && (RollerSeq == 1)){       //離した検出
    RollerSeq = 2;
    delay(50);
  }else if(RollerSeq == 2){         //処理
    if(RollerOnOff == 0){
      motor[ROLLER].TxVel = 15000;
      RollerOnOff = 1;
    }else{
      motor[ROLLER].TxVel = 0;
      RollerOnOff = 0;
    }
    RollerSeq = 0;
  }
}

void Pitch(void){
  //サーボのお勉強がてらここも消すかも
  ServoON(SERVO1, (int)(RxData[2]*90/100 + 90));
}