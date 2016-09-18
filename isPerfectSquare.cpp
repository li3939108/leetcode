#include <iostream>

bool isPerfectSquare(int num) {
    if(num < 0){
        return false;
    }else if(num == 1){
        return true;
    }else{
        long x0 = num / 2, x2 = 0;
        long x1 = x0;
        while(true){
			std::cout << "x2 : " << x2 << " x1 :" << x1 << std::endl ;
            x2 = (long long)x1 -  ((long long)(x1*x1) - num) / (long long)(x1+x1) ;
			std::cout << "x2 : " << x2 << " x1 :" << x1 << std::endl ;
            if(x2 == x1) { 
                if(x1*x1-num > 0){
                    x2 = x1 - 1;
                }else {
                    x2 = x1 + 1;
                }
            }
            if(x2*x2 == num){
                return true;
            }else{
                if(x0 == x2){
					std::cout << x0 << " converged" << std::endl ;
                    long i = 0;
                    for(i = x0; i <= x1; i++){
                        if(i*i == num){
                            return true;
                        }
                    }
                    return false;
                }
                x0 = x1;
                x1 = x2;
            }
        }
    }
}

int main(){
	std::cout << isPerfectSquare(808201)<< std::endl;	
	std::cout << isPerfectSquare(100) << std::endl;
}
