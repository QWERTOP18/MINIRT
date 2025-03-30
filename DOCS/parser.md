# パーサー概要

rt ファイルをパースして線形リストの形でもつ

```c
typedef struct s_list
{
	int				type;
	struct s_list	*next;
	void			*data;
}					t_list;
```

```
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```

```c
typedef struct s_material
{
	t_scaled_col	color;
	double gloss; // ここは設定しなくても良い

}					t_material;

```
