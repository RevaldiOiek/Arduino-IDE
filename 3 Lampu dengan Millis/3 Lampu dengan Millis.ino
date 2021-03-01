const int ledMerah = PA1; 
const int ledKuning = PA2;
const int ledHijau = PA3;

int WaktuSerial = 1000; 
unsigned long WaktuSebelumnya = 0;  // waktu serial print diupdate
unsigned long wl = 0; //waktu lampu diupdate
unsigned long waktuberjalan = 0; 
int WaktuLampuMerah = 8000;
int WaktuLampuKuning = 2000;
int WaktuLampuHijau = 5000;

int x = 1;

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  Serial.begin(9600);
 
}
void loop() {
  waktuberjalan = millis();
    // Call the function to change the lights
    if(x==1){
     Led_Merah(); 
    } 
    if(x==2){
      Led_Kuning(); 
    } 
    if(x==3){
      Led_Hijau();
    }
    if(x>3){
      x=1;
    }

    if(WaktuSerial < (waktuberjalan-WaktuSebelumnya)){
      WaktuSebelumnya = waktuberjalan;
      if(x==1){
        Serial.println("Lampu merah menyala");
      } else if(x==2){
        Serial.println("Lampu kuning menyala");
      }else {
        Serial.println("Lampu hijau menyala");
      }
    }
}
 
void Led_Merah() {
  digitalWrite(ledMerah, HIGH);
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledHijau, LOW);
  if(WaktuLampuMerah < (waktuberjalan - wl)){
  x = x+1;
  wl = waktuberjalan;
  }
  
}
void Led_Kuning(){
  digitalWrite(ledMerah, LOW);
  digitalWrite(ledKuning, HIGH);
  digitalWrite(ledHijau, LOW);
  if(WaktuLampuKuning < (waktuberjalan - wl)){
  x=x+1;
  wl = waktuberjalan;
  }
}

void Led_Hijau(){
  digitalWrite(ledMerah, LOW); 
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledHijau, HIGH);
  if(WaktuLampuHijau < (waktuberjalan - wl)){
  x=x+1;
  wl = waktuberjalan;
  }
}
