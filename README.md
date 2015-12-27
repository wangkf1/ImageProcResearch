# ImageProcResearch
##Image Processing research project
This is a small research project to program a short script for Viviana Medina, PhD student in Department of Plant Sciences. The goal is to be able to loop through a directory of plant row images, and for each image, detect the percentage of plant matter that is in the image. In other words, how many squares of pixels are considered "green"?  

To do this, each image is separated into Red, Green, and Blue pixel values (RGB). Using ImageJ, an imaging software, we noticed that for plants, no matter if they are in shadow or lit by the sun, the values remain consistent across red, green, and blue, and that there is a drastic difference in those values if the pixel is dirt or another object. Using that fact, the plants are separated from the dirt, and further separated into shadowed or canopy plant matter.  

Because none of the undergraduates working on this project had experience in computational image processing, this was the best solution given the time and experience constraints. We used OpenCV with C++ and combined all into one script, [completeProg.cpp](/completeProg.cpp). 
