#include <PseudoTask.h>

// インスタンス生成
CycleTask led(1000);  // 周期タスク(1秒毎に実行)
OneShotTask alarm;    // 単発タスク(1回だけ実行)

// 制御用変数
int state = 0;

void setup() {
  // シリアル通信の初期化
  Serial.begin(115200);

  // GPIOの初期化
  pinMode(LED_BUILTIN, OUTPUT);

  // 周期タスクを開始
  led.start();
}

void loop() {
  // タスクの時間監視
  // 1ms以下の頻度で実行すると正常に動作
  led.update();
  alarm.update();

  // 周期タスクの実行
  if (led.isFired()) {
    Serial.println("CycleTask Fired.");
    state = 1 - state;
    digitalWrite(LED_BUILTIN, state);

    if (state == 1) {
      // 単発タスクをスタート
      // 500ms後にタスクを実行
      alarm.start(500);
    }
  }

  // 単発タスクの実行
  if (alarm.isFired()) {
    Serial.println("OneShotTask Fired.");
  }
}
