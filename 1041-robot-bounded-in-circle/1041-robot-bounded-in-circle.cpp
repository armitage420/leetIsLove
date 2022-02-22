class Solution {
public:
    bool isRobotBounded(string instructions) {
        int angle = 0, x = 0, y = 0;
        for(char ch : instructions){
            if(ch == 'G'){
                if(angle == 0)
                    y+=1;
                else if(angle == 90)
                    x+=1;
                else if(angle == 180)
                    y-=1;
                else
                    x-=1;
            }else if(ch == 'L'){
                angle += 270;
            }else{
                angle += 90;
            }
            
            angle %= 360;
        }
        
        if(!x && !y)
            return true;
        if(angle != 0)
            return true;
        
        return false;
    }
};

// "GLRLLGLL"