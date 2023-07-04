#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void removeDuplicates(vector<double>& numbers, size_t& count);

int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector<double> numbers(number_count);
    for (int i = 0; i < number_count; i++)
        cin >> numbers[i];
    removeDuplicates(numbers, number_count);
    for (int i = 0; i < number_count; i++)
        cout << numbers[i] << ' ';
    cout << '\n' << '\n';
    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;
    vector<size_t> bins(bin_count);
    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
    double bin_size = (max - min) / bin_count;
    size_t max_count = 0;
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        size_t j;
        for (j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
                if (bins[j] > max_count)
                    max_count = bins[j];
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
            if (bins[bin_count - 1] > max_count)
                max_count = bins[bin_count - 1];
        }
    }
    double scaling_factor = 1.0;
    size_t height;
    if (max_count > 76)
        scaling_factor = 76 / static_cast<double>(max_count);
    for (int i = 0; i < bin_count; i++) {
        if (bins[i] < 100)
            cout << ' ';
        if (bins[i] < 10)
            cout << ' ';
        cout << bins[i] << '|';
        height = static_cast<size_t>(scaling_factor * bins[i]);
        for (int j = 0; j < height; j++)
            cout << '*';
        cout << '\n';
    }
}

void removeDuplicates(vector<double> &numbers, size_t &count) {
    vector<double> dublicates;
    bool is_find;
    int i = 0;
    while (i < count) {
        is_find = false;
        for (int j = 0; j < dublicates.size(); j++) {
            if (fabs(dublicates[j] - numbers[i]) < 0.000001) {
                is_find = true;
                break;
            }
        }
        if (is_find) {
            numbers.erase(numbers.begin() + i);
            count--;
        }
        else {
            dublicates.push_back(numbers[i]);
            i++;
        }
    }
}