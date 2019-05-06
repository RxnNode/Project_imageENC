# 結果
## `原始圖片`
<p align="center">
  <img src="/direct_hiding/images/image.jpg" width="300" alt="original image">
  jpg轉bmp
  <img src="/direct_hiding/images/imgb.bmp" width="300" alt="original image">
</p>

```
                file size : 205,847 byte                       file size : 1,048,630 byte
                  image size : 512 x 512    jpg轉bmp(32bits)   image size : 512 x 512
```
**已bmp檔做隱藏，至多可以以1bit隱藏一個131078 byte的檔案**


## `寫入檔案` [Text file](/direct_hiding/text_source/secret)
```
file size : 113 KB (115,390 byte)
```

## `輸出圖片`
<p align="center">
  1bit隱藏
  <img src="/direct_hiding/out/out_0.bmp" width="200">  
  <img src="/direct_hiding/out/out_1.bmp" width="200">
  2bits隱藏
</p>
<p align="center">
  3bit隱藏
  <img src="/direct_hiding/out/out_2.bmp" width="200">  
  <img src="/direct_hiding/out/out_3.bmp" width="200">
  4bits隱藏
</p>
<p align="center">
  5bit隱藏
  <img src="/direct_hiding/out/out_4.bmp" width="200">  
  <img src="/direct_hiding/out/out_5.bmp" width="200">
  6bits隱藏
</p>
<p align="center">
  7bit隱藏
  <img src="/direct_hiding/out/out_6.bmp" width="200">  
  <img src="/direct_hiding/out/out_7.bmp" width="200">
  8bits隱藏
</p>

---

# PSNR
<p align="center">
  <img src="/direct_hiding/chart/1.png" width="500">  
  <img src="/direct_hiding/chart/2.png" width="500">
</p>

```
1 bits hiding psnr : 110.815811
Sum: 52455.000000
MSE: 0.512256
2 bits hiding psnr : 80.724538
Sum: 316797.000000
MSE: 3.093721
3 bits hiding psnr : 44.758427
Sum: 1747692.000000
MSE: 17.067305
4 bits hiding psnr : 10.602624
Sum: 8019200.000000
MSE: 78.312500
5 bits hiding psnr : -19.868228
Sum: 35096241.000000
MSE: 342.736729
6 bits hiding psnr : -49.393335
Sum: 129781958.000000
MSE: 1267.401934
7 bits hiding psnr : -75.548571
Sum: 446791280.000000
MSE: 4363.196094
8 bits hiding psnr : -100.273286
```
<p align="center">
  <img src="/direct_hiding/chart/2.png" width="600">
</p>

```
MSE: 0.115652
1 bits hiding psnr : 110.489294
Sum: 636388.000000
MSE: 0.606907
2 bits hiding psnr : 77.333514
Sum: 3586780.000000
MSE: 3.420620
3 bits hiding psnr : 42.749480
Sum: 16466683.000000
MSE: 15.703853
4 bits hiding psnr : 12.267795
Sum: 58822680.000000
MSE: 56.097679
5 bits hiding psnr : -13.195972
Sum: 194670699.000000
MSE: 185.652446
6 bits hiding psnr : -37.131610
Sum: 715977139.000000
MSE: 682.809009
7 bits hiding psnr : -63.178387
Sum: 2064158717.000000
MSE: 1968.535153
8 bits hiding psnr : -84.354983
```

# 結構
:file_folder:**direct_hiding**  
  L:file_folder:**text_source** : contains text files  
  L:file_folder:**out** : contains output images  
  L:file_folder:**images** : original images  

---

#
