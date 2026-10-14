class DataStream {
public:
    int k;
    int value;
    int count = 0;

    DataStream(int value, int k) {
        this->k = k;
        this->value = value;
    }

    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }

        return count >= k;
    }
};