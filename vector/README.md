# Vector Math Library

このライブラリは、3D グラフィックスやレイトレーシングで使用される**ベクトル演算**, **幾何オブジェクト**, **数学的方程式の解法**などを提供するヘッダーファイルおよび実装です。

---

## 概要

- 3D ベクトル演算 (`t_vec`)
- 直線、球、平面、円柱、三角形、円錐の構造体定義とユーティリティ
- 線形方程式・二次方程式の解 (`solve_eq`)
- 距離計算や正規化などのベクトル操作関数

---

---

## データ構造

### ベクトル型

```c
typedef struct s_vec {
	double x;
	double y;
	double z;
} t_vec;
```

- ベクトルとして使う他、点や方向としてもエイリアスが定義されています。
  - `t_unit_vec`: 正規化された方向ベクトル
  - `t_pos_vec`: 座標点

---

### 方程式

```c
typedef struct s_roots {
	int n;       // 解の個数（0, 1, 2, -1）
	double x1;   // 小さい方の解
	double x2;   // 大きい方の解
} t_roots;
```

- `n == -1`: 無限解
- `n == 0`: 実数解なし
- `n == 1`: 重解（x1 == x2）
- `n == 2`: 異なる 2 実数解

# 使用例:

### ベクトル演算

```c
t_vec vec_add(t_vec a, t_vec b);
t_vec vec_cross(t_vec a, t_vec b);
double vec_dot(t_vec a, t_vec b);
t_unit_vec vec_normalize(t_vec v);
double vec_distance(t_vec a, t_vec b);
```

### 幾何オブジェクトの作成

```c
t_sphere *sphere_new(t_pos_vec center, double radius, void *material);
t_plane  *plane_new(t_pos_vec pos, t_vec normal, void *material);
t_cone   *cone_new(...);
```

---

## 定数

- `FT_EPSILON`: 計算誤差許容値（浮動小数点比較用）

---

## 使用例

```c
t_vec v1 = vec(1, 2, 3);
t_vec v2 = vec(4, 5, 6);
t_vec cross = vec_cross(v1, v2);
double dot = vec_dot(v1, v2);

t_roots r = solve_eq(1, -3, 2); // x² - 3x + 2 = 0
```

---

## メモリ管理

各オブジェクト (`sphere`, `plane`, etc.) は `*_new()` によって `malloc` されます。使用後は `*_clear()` を必ず呼び出してメモリリークを防止してください。

---
