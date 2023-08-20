void Init(void){

  pinMode(LED1,  OUTPUT);
  pinMode(LED2,  OUTPUT);
  pinMode(LED3,  OUTPUT);
  pinMode(LED4,  OUTPUT);
  pinMode(LED5,  OUTPUT);
  pinMode(LED6,  OUTPUT);
  pinMode(LED7,  OUTPUT);
  pinMode(LED8,  OUTPUT);
  pinMode(LED9,  OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  // pinMode(LED13, OUTPUT);  //SPIで使用
  // pinMode(LED14, OUTPUT);  //SPIで使用
  // pinMode(LED15, OUTPUT);  //SPIで使用
  pinMode(LED16, OUTPUT);

  pinMode(SW1,  INPUT);
  pinMode(SW2,  INPUT);
  pinMode(SW3,  INPUT);
  pinMode(SW4,  INPUT);
  pinMode(SW5,  INPUT);
  pinMode(SW6,  INPUT);
  pinMode(SW7,  INPUT);
  pinMode(SW8,  INPUT);
  pinMode(SW9,  INPUT);
  pinMode(SW10, INPUT);
  pinMode(SW11, INPUT);
  pinMode(SW12, INPUT);
  pinMode(SW13, INPUT); 
  pinMode(SW14, INPUT);
  pinMode(SW15, INPUT);
  pinMode(SW16, INPUT);

  pinMode(AF1, INPUT);
  pinMode(AF2, INPUT);


}

/********  Buzzer  ********/
void BuzzerON(void){
  analogWrite(BUZZER, 255);
}
void BuzzerOFF(void){
  analogWrite(BUZZER, 0);
}
void Buzzer1ON(void){
  analogWrite(BUZZER, 55);
}
void BuzzerInitOK(void){
  
  BuzzerON();
  delay(100);
  BuzzerOFF();
  delay(100);
  BuzzerON();
  delay(100);
  BuzzerOFF();
  delay(100);
  BuzzerON();
  delay(100);
  BuzzerOFF();
  delay(100);

}


/********  Debug LED  ********/
void SensorDebugLED(void){

  if(digitalRead(SW1)){
    digitalWrite(LED1, LOW);
  }else{
    digitalWrite(LED1, HIGH);
  }
  if(digitalRead(SW2)){
    digitalWrite(LED2, LOW);
  }else{
    digitalWrite(LED2, HIGH);
  }
  if(digitalRead(SW3)){
    digitalWrite(LED3, LOW);
  }else{
    digitalWrite(LED3, HIGH);
  }
  if(digitalRead(SW4)){
    digitalWrite(LED4, LOW);
  }else{
    digitalWrite(LED4, HIGH);
  }
  if(digitalRead(SW5)){
    digitalWrite(LED5, LOW);
  }else{
    digitalWrite(LED5, HIGH);
  }
  if(digitalRead(SW6)){
    digitalWrite(LED6, LOW);
  }else{
    digitalWrite(LED6, HIGH);
  }
  if(digitalRead(SW7)){
    digitalWrite(LED7, LOW);
  }else{
    digitalWrite(LED7, HIGH);
  }
  if(digitalRead(SW8)){
    digitalWrite(LED8, LOW);
  }else{
    digitalWrite(LED8, HIGH);
  }
  if(digitalRead(SW9)){
    digitalWrite(LED9, LOW);
  }else{
    digitalWrite(LED9, HIGH);
  }
  if(digitalRead(SW10)){
    digitalWrite(LED10, LOW);
  }else{
    digitalWrite(LED10, HIGH);
  }
  if(digitalRead(SW11)){
    digitalWrite(LED11, LOW);
  }else{
    digitalWrite(LED11, HIGH);
  }
  if(digitalRead(SW12)){
    digitalWrite(LED12, LOW);
  }else{
    digitalWrite(LED12, HIGH);
  }
  //SPIで使用
  /*
  if(digitalRead(SW13)){
    digitalWrite(LED13, LOW);
  }else{
    digitalWrite(LED13, HIGH);
  }
  if(digitalRead(SW14)){
    digitalWrite(LED14, LOW);
  }else{
    digitalWrite(LED14, HIGH);
  }
  if(digitalRead(SW15)){
    digitalWrite(LED15, LOW);
  }else{
    digitalWrite(LED15, HIGH);
  }
  */
  if(digitalRead(SW16)){
    digitalWrite(LED16, LOW);
  }else{
    digitalWrite(LED16, HIGH);
  }

}