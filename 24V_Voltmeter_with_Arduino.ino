//24V VOLTMETER WITH ARDUINO
//by: Lucas Leonardo

float val = 0.0, conv[100], ctr_vector[100];
int ctr_vector2[100];

void setup(){
  Serial.begin(115200);    
}

float get_voltage(){
  int j;
  for (j = 0; j <= 99; j++){
    val = analogRead(A0) - analogRead(A1);
    conv[j] = val/1023*24;
    //Serial.print(j); Serial.print(" "); Serial.println(conv[j]);
    delay(1);
  }
}

float plot(float conv[100]){
  float control = 0, plot1[100], plot2[100];
  int i, j, control2 = 0;
  for (i = 0; i <= 99; i++){
    plot1[i] = 0;
    plot2[i] = 0;
  }
 for (i = 0; i <= 99; i++){
  if (conv[i] != 0){
    for (j = i; j <= 99; j++){
      if (j == i){
        control = conv[j];
      }
      if (control >= conv[j]){
        control = conv[j];
      }
    }
    for (j = 0; j <= 99; j++){
      if (control == conv[j]){
        conv[j] = 0;
        control2++;
      }
    }
  }
  for (j = 0; j <= 99; j++){
    if (plot1[j] == 0){
      plot1[j] = control;
      plot2[j] = control2;
      j = 100;
      control2 = 0;
   }
  }
 }
 for (i = 0; i <= 99; i++){
  ctr_vector[i] = plot1[i];
  ctr_vector2[i] = plot2[i];
 }
}

void loop(){
  int i;
  for(i = 0; i <= 99; i++){
    ctr_vector[i] = 0;
  }
  get_voltage();
  plot(conv);
  for (i = 0; i <= 99; i++){
    if(ctr_vector[i] != 0 && ctr_vector2[i] != 0){
      Serial.print(ctr_vector[i], 5); Serial.print(" "); Serial.println(ctr_vector2[i]);
      delay(10);
    }
  }
}
