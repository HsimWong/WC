raw_image = imread();
% 0.3 0.59 0.11
r = raw_image[:,:,1];
g = raw_image[:,:,2];
b = raw_image[:,:,2];


gray = 0.3 * r + 0.59 * g + 0.11 * b;
