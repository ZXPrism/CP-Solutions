class FoodRatings {
public:
    std::unordered_map<std::string, std::pair<std::string, int>> _FoodData;
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> _CuisineData;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; auto &food : foods) {
            _FoodData[food] = {cuisines[i], ratings[i]};
            _CuisineData[cuisines[i]].insert({-ratings[i], food});
            ++i;
        }
    }

    void changeRating(string food, int newRating) {
        auto &[cuisine, rating] = _FoodData[food];
        _CuisineData[cuisine].erase({-rating, food});
        _CuisineData[cuisine].insert({-newRating, food});
        rating = newRating;
    }

    string highestRated(string cuisine) {
        return _CuisineData[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
