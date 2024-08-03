float val = 0.0, conv[300], ctr_vector[300];

void setup(){
	Serial.begin(115200);    
}

float get_voltage(){
  int j;
  for (j = 0; j <= 299; j++){
    val = analogRead(A0) - analogRead(A1);
    conv[j] = val/1023*24;
    //Serial.print(j); Serial.print(" "); Serial.println(conv[j])
    delay(1);
  }
}

float plot(float conv[300]){
  float ctr = NULL;
  int j ,k;
  for (k = 0; k <= 299; k++){
    for (j = 0; j <= 299; j++){
      if (ctr == NULL && conv[j] != NULL){
        ctr = conv[j];
      }
      if (ctr > conv[j] && conv[j] != NULL){
        ctr = conv[j];
      }
    }
    ctr_vector[k] = ctr;
    for(j = 0; j <= 299; j++){
      if(conv[j] != NULL && conv[j] == ctr){
        conv[j] = NULL;
        j = 299;
      }
    }
  }
}

void loop(){
  get_voltage();
  plot(conv);
  int i;
  for (i = 0; i <= 299; i++){
    Serial.println(ctr_vector[i]);
    delay(10);
  }
}
