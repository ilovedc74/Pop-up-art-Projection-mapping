# Pop-up-art-Projection-mapping
This is a term project for a computational arts course

## Itroduction

Get Tangled is a projection mapping project on pyramid cubes. Playing with dots and lines throughout the piece, and color transformations alongside.

## Technical

I used Openframeworks, ofxJSON, ofxPimapper, ofXmlSettings to code. Some challenges included the fluency of the first scene to be drawn and the exact portion to fill in the square, I had to do some math for it and thanks to Giacomo for introducing me to "polylines" to achieve this.

Originally, the lines couldn't draw smoothly. This however was achieved by writing a clean function to make the codes clean and run faster. Before, there would always be a lag for the drawn pixel and also I had to create a vector to run a for loop to draw the squares, otherwise the squares really gets "tangled" with each other, and a undesired diagonal line would be drawn between the squares. 

## Concept and background research

Originally I wanted to create some lines between the dots and set the width to a thin line, inspired by: https://www.flickr.com/photos/introspector/5709396891/in/pool-1515493@N25/lightbox/

And close organized lines that make into shapes: https://www.pinterest.co.uk/pin/393853929885451858/


### Computer Demo

[![Projection mapping computer demo](http://img.youtube.com/vi/MZgyz4SlSbM/0.jpg)](http://www.youtube.com/watch?v=MZgyz4SlSbM)


### Live Demo


[![Projection mapping live](http://img.youtube.com/vi/3TosNJKo_wI/0.jpg)](http://www.youtube.com/watch?v=3TosNJKo_wI)

