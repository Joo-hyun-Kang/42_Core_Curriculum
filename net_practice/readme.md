## ネットプラクティスという課題について

***[NetPractice Notionページ](https://wide-yarrow-176.notion.site/NetPractice-da89a17a9e7d442a904161318590d807?pvs=4)***


ネットプラクティスは、PC から内部ネットワーク、ルーター、外部ウェブサイトへの接続をシミュレーションを通じて練習する課題です。

<img width="810" alt="スクリーンショット 2024-07-21 0 57 27" src="https://github.com/user-attachments/assets/7b0e467f-228a-4e0d-b071-b67441f09d31">




```tsx
- ****** Goal ID 2 ********

forward way : C -> Somewhere on the Net (8.8.8.8)
on C : packet accepted
on C: destination does not match any interface. pass through routing table
on C : route match 0.0.0.0/0
on C: send to gateway 130.59.72.18 through interface C1
on R2 : packet accepted
on R2: destination does not match any interface. pass through routing table
on R2 : route match 0.0.0.0/0
on R2: send to gateway 130.59.72.62 through interface R21
on R1 : packet accepted
on R1: destination does not match any interface. pass through routing table
on R1 : route match 0.0.0.0/0
on R1: send to gateway 163.69.250.1 through interface R12
on I : packet accepted
on I: destination IP reached

reverse way : Somewhere on the Net -> C (130.59.72.17)
on I : packet accepted
on I: destination does not match any interface. pass through routing table
on I : route match 130.59.72.0/26
on I: send to gateway 163.69.250.12 through interface I1
on R1 : packet accepted
on R1: destination does not match any interface. pass through routing table
on R1 : route match 0.0.0.0/0
on R1: send to gateway 163.69.250.1 through interface R12
on I : loop detected
```


### 主な概念

- OSI 7 階層モデル
- IP アドレスとサブネットティング
- スイッチとルーターの違い
- ループバックアドレス
- ルーティングテーブル
- デフォルトゲートウェイ

### 関連事項

ネットプラクティスのシミュレーションを通じて理解できること

- ネットワーク構成の際に、NAT とサブネットティングの組み合わせ
- PC 上で VM や Docker を利用する際のネットワークの流れ
  - NAT + サブネットティング + ポートフォワーディング

プライベートネットワーク
