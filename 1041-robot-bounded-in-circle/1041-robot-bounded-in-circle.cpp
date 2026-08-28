class Solution{
public:
    bool isRobotBounded(string instructions){
        int dir=0,xpos=0,ypos=0;

        for(int idx=0;idx<instructions.length();idx++){
            if(instructions[idx]=='L')
                dir=(dir+1)%4;
            else if(instructions[idx]=='R')
                dir=(dir+3)%4;
            else{
                if(dir==0) xpos++;
                else if(dir==1) ypos++;
                else if(dir==2) xpos--;
                else ypos--;
            }
        }

        if(xpos==0&&ypos==0) return true;
        if(dir!=0) return true;
        return false;
    }
};