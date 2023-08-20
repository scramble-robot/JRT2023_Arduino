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