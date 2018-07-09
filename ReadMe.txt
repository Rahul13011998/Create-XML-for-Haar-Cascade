1. Change below file to different name (or conflict with ROS opencv when using imageScrape.py):
/opt/ros/kinetic/lib/python2.7/dist-packages/cv2.so

2. Use imageScrape.py to collect all negative images:
python3 imageScrape.py street neg
python3 imageScrape.py people neg
python3 imageScrape.py room neg
etc..

3. Use createDescriptor.py to create bg.txt:
python3 createDescriptor.py

4. Use resizeImage.cpp to create 50 by 50 pos image:
makeCV resizeImage
./resizeImage

5. Make data & info folder:
mkdir data
mkdir info

6. Run Exe files in this dir: /opt/opencv/release/bin or will cause a conflict with ROS

7. Create test samples from single image applying distortions:
/opt/opencv/release/bin/./opencv_createsamples -img watchResized.jpg -bg bg.txt -info info/info.lst -pngoutput info -maxxangle 0.5 -maxyangle 0.5 -maxzangle 0.5 -num 950

8. Create training samples from images collection:
/opt/opencv/release/bin/./opencv_createsamples -info info/info.lst -num 950 -w 20 -h 20 -vec positives.vec

9. Train:
/opt/opencv/release/bin/./opencv_traincascade -data data -vec positives.vec -bg bg.txt -numPos 1800 -numNeg 1800 -numStages 10 -w 20 -h 20

/opt/opencv/release/bin/./opencv_traincascade -data data -vec positives.vec -bg bg.txt -numPos 900 -numNeg 900 -numStages 11 -w 20 -h 20
 *1800 --> insufficient pos images


