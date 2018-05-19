%X=[2 3 9 7 4 1 2 8];
%Y=[7 4 5 3 1 3 2 3];

X=[4 2 6 1 5 8 7 3 9];
Y=[9 8 7 4 1 2 3 6 5];
%Append the first point to the end

ln=size(X,2); %Length

coords=[X;Y;ones(1,ln)]; %A coordinate matrix

%%Find Bottom-most Point
bPos=1;

for i=2:ln
    if Y(i)<Y(bPos)
        bPos=i;
    end
end

%%Repeat till original point is reached
origin=bPos;
t=1;
conHul=[];

while origin~=bPos || t==1
    
    conHul=[conHul;origin]; %Append all convex Hull 
    t=t+1;
    %Translate All points to originPoint
    chMat=[coords(1,origin);coords(2,origin);0];
    for i=1:ln
       coords(:,i)=coords(:,i)-chMat;
    end
    
    %Find next point which has smallest angle
    min=pi;
    minpos=origin;
    for i=1:ln
        if i~=origin  %condition to avoid same point to be selected
            x2=coords(1,i);
            y2=coords(2,i);
            theta=atan(y2/x2);
            
            %condition to check if angle is >90 degrees
            if x2<=0
                theta=theta+pi;
            end
            %Store minimum value and position
            if theta<min
                minpos=i;
                min=theta;
            end
        end
    end
    
    %%Assign minimum position to origin and Rotate all points 
    origin=minpos;
    rtheta=[cos(min),sin(min),0;-sin(min),cos(min),0;0,0,1];
    coords=rtheta*coords;
    
end

%%DeBug
conHul

%%To Display Convex HUll
coords2=[];
for i=1:size(conHul,1)
    coords2=[coords2' ; [X(conHul(i)) Y(conHul(i)) 1]]';
end
coords2
plot(X,Y,'rx');hold on;
pause;
plot(coords2(1,:),coords2(2,:),'b-');
%%---------------------------------------------