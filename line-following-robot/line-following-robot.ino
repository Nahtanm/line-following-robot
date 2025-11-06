// Motor esquerdo
#define pinoEnableA 10
#define pinoIN1 9
#define pinoIN2 8

// Motor direito
#define pinoEnableB 5
#define pinoIN3 7
#define pinoIN4 6

// Sensores Infravermelho (2 sensores)
#define pinoSensorEsquerdo A1  // Sensor Esquerdo
#define pinoSensorDireito A0   // Sensor Direito

// Variáveis
int sensorEsquerdo = 0;
int sensorDireito = 0;

// Velocidades dos motores
const int velMAX = 85;

// Valores de calibração dos sensores
int pisoBranco = 50;
int pisoPreto = 50;

void setup() {
  pinMode(pinoEnableA, OUTPUT);
  pinMode(pinoIN1, OUTPUT);
  pinMode(pinoIN2, OUTPUT);

  pinMode(pinoEnableB, OUTPUT);
  pinMode(pinoIN3, OUTPUT);
  pinMode(pinoIN4, OUTPUT);

  pinMode(pinoSensorEsquerdo, INPUT);
  pinMode(pinoSensorDireito, INPUT);

  Serial.begin(9600);
}

void loop() {

  sensorEsquerdo = analogRead(pinoSensorEsquerdo);
  sensorDireito = analogRead(pinoSensorDireito);

  Serial.print("S1: ");
  Serial.print(sensorEsquerdo);
  Serial.print("  S2: ");
  Serial.println(sensorDireito);

  if (sensorEsquerdo <= pisoBranco && sensorDireito <= pisoBranco) {
    moveFrente(velMAX);
  } else if (sensorEsquerdo <= pisoBranco && sensorDireito >= pisoPreto) {
    moveDireitaPouco(velMAX);
  } else if (sensorEsquerdo >= pisoPreto && sensorDireito <= pisoBranco) {
    moveEsquerdaPouco(velMAX);
  } else if (sensorEsquerdo >= pisoPreto && sensorDireito >= pisoPreto) {
    paraCarro();
  }
  delay(40);
}

// Funções de movimento
void moveFrente(int vel) {
  digitalWrite(pinoIN1, HIGH);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoEnableA, vel);

  digitalWrite(pinoIN3, HIGH);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoEnableB, vel);
}

void moveDireitaPouco(int vel) {
  digitalWrite(pinoIN1, HIGH);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoEnableA, vel + 20);

  digitalWrite(pinoIN3, LOW);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoEnableB, 0);
}

void moveEsquerdaPouco(int vel) {
  digitalWrite(pinoIN1, LOW);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoEnableA, 0);

  digitalWrite(pinoIN3, HIGH);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoEnableB, vel + 20);
}

void paraCarro() {
  digitalWrite(pinoIN1, LOW);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoEnableA, 0);

  digitalWrite(pinoIN3, LOW);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoEnableB, 0);
}