void RxController(void){

  if(Serial1.available()){

    String StrData = Serial1.readStringUntil('\n');
    delay(10);
    StrData.remove(0,1);
    Serial.println(StrData);
    
    for (int i = 0; i < 4; i++){
      int check = StrData.indexOf(',');
      String SubData = StrData.substring(0, check);
      StrData = StrData.substring(check+1);

      if(i == 3){
        char temp[5];
        SubData.toCharArray(temp, 5);
        RxData[3] = (int)(strtol(temp, NULL, 2));
      }else{
        RxData[i] = SubData.toInt();
      }
      
    }

    // Serial.print("RxData[0]= ");
    // Serial.print(RxData[0]);
    // Serial.print(", RxData[1]= ");
    // Serial.print(RxData[1]);
    // Serial.print(", RxData[2]= ");
    // Serial.print(RxData[2]);
    // Serial.print(", RxData[3]= ");
    // Serial.println(RxData[3]);

  }
}