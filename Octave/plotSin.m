
function plotSin(f1,f2)
	if nargin == 1
		x = linspace(0, 4*pi, f1*100+1);
		y = sin(f1*x);
		figure
		plot(x,y)
	elseif nargin == 2
		x = linspace(0,4*pi,f1*20);
		y = linspace(0,4*pi,f2*20);
		[X, Y] = meshgrid(x,y);
		Z = sin(f1*X)+sin(f2*Y);
		surf(X,Y,Z);
	end
