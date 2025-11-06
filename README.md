# 🚗 Robô Seguidor de Linha – Arduino

Este projeto implementa um **robô seguidor de linha** utilizando Arduino, dois motores DC com driver ponte-H (L298N, L293D ou similar) e dois sensores infravermelhos (IR) analógicos.  
O robô é capaz de identificar linhas escuras sobre superfície clara e ajustar sua trajetória automaticamente.

---

## ✅ Funcionalidades

- Leitura contínua de **2 sensores IR** (esquerdo e direito)  
- Detecção de **piso branco** e **linha preta**  
- Controle automático de movimentação:
  - Seguir em frente
  - Curvas leves para esquerda e direita
  - Parada total
- Velocidade configurável via PWM

---

## 🛠️ Componentes necessários

- Arduino Uno / Nano / Mega  
- 2 Motores DC  
- Driver de motor (L298N ou L293D)  
- 2 Sensores infravermelhos analógicos (TCRT5000 ou similar)  
- Fonte 7–12V  
- Jumpers e chassi de robô  

---

## 📌 Ligações

### Motores

| Motor     | Enable A | IN1 | IN2 |
|-----------|----------|-----|-----|
| Esquerdo  | D10      | D9  | D8  |

| Motor     | Enable B| IN1 | IN2 |
|-----------|---------|-----|-----|
| Direito   | D5      | D7  | D6  |

### Sensores IR

| Sensor     | Pino |
|------------|------|
| Esquerdo   | A1   |
| Direito    | A0   |

---

## ⚙️ Como o código funciona

1. Os sensores IR são lidos com `analogRead()`.
2. O sistema compara os valores com as variáveis de calibração (`pisoBranco` e `pisoPreto`).
3. Com base nisso, o robô executa uma ação:
   - **Ambos no branco:** segue em frente  
   - **Direito no preto:** vira à direita  
   - **Esquerdo no preto:** vira à esquerda  
   - **Ambos no preto:** para  
4. Os motores são controlados por sinais digitais para o sentido e PWM para velocidade.

---

## 📊 Lógica de Decisão

