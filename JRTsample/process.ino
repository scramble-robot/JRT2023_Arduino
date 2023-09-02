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