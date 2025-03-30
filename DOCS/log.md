## objs

`void	log_objs(t_objects *objs);`すべてのオブジェクトの概要を取得

```

---- obj -------------------------
num_of_objs  : 3
num_of_camera: 5
id_of_camera : 0
num_of_light : 1
[0]
----------------------------------
```

## pixel

`void	log_pixel(t_pixel **pixel, int y, int x)`クリックしたピクセルにあるオブジェクトの情報を取得

```
-- (0455, 0331) ------------------
sphere
x:      5.00
y:      0.00
z:      0.00

r:      3.00

dist :  19.343017
intersection
x:      3.86
y:      0.48
z:     -1.21

----------------------------------
```

## light

`void	log_light(t_light **light, int size)`各 light の ON/OFF を表示
