class FoodRatings {
public:
    std::unordered_map<std::string, std::pair<std::string, int>> _FoodData;
    std::unordered_map<
        std::string, std::priority_queue<std::pair<int, std::string>,
                                         std::vector<std::pair<int, std::string>>, std::greater<>>>
        _CuisineData;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; auto &food : foods) {
            _FoodData[food] = {cuisines[i], ratings[i]};
            _CuisineData[cuisines[i]].push({-ratings[i], food});
            ++i;
        }
    }

    void changeRating(string food, int newRating) {
        auto &[cuisine, rating] = _FoodData[food];
        _CuisineData[cuisine].push({-newRating, food});
        rating = newRating;
    }

    string highestRated(string cuisine) {
        auto &heap = _CuisineData[cuisine];
        while (1) {
            auto [rating, name] = heap.top();
            if (_FoodData[name].second != -rating) {
                heap.pop();
            } else {
                break;
            }
        }
        return heap.top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
