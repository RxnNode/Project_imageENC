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
## `部分採樣`

<p align="center">
  <img src="/direct_hiding/chart/1.png" width="500">  
</p>

```
1 bits hiding psnr : 110.815811
2 bits hiding psnr : 80.724538
3 bits hiding psnr : 44.758427
4 bits hiding psnr : 10.602624
5 bits hiding psnr : -19.868228
6 bits hiding psnr : -49.393335
7 bits hiding psnr : -75.548571
8 bits hiding psnr : -100.273286
```
## `全圖採樣`

<p align="center">
  <img src="/direct_hiding/chart/2.png" width="500">
</p>

```
1 bits hiding psnr : 110.489294
2 bits hiding psnr : 77.333514
3 bits hiding psnr : 42.749480
4 bits hiding psnr : 12.267795
5 bits hiding psnr : -13.195972
6 bits hiding psnr : -37.131610
7 bits hiding psnr : -63.178387
8 bits hiding psnr : -84.354983
```
---

# 結構
:file_folder:**direct_hiding**  
  L:file_folder:**text_source** : contains text files  
  L:file_folder:**out** : contains output images  
  L:file_folder:**images** : original images  

---

#
