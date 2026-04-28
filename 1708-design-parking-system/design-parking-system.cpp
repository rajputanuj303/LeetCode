class ParkingSystem {
public:
    int bigPark, medPark, smallPark;
    ParkingSystem(int big, int medium, int small) {
        bigPark = big;
        medPark = medium;
        smallPark = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bigPark == 0) return false;
            bigPark--;
        }else if(carType == 2){
            if(medPark == 0) return false;
            medPark--;
        }else if(carType == 3){
            if(smallPark == 0) return false;
            smallPark--;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */