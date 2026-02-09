vector<int> result;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    while (result.size() == 0 || i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (result.back() != arr2[i])
            {
                result.push_back(arr2[i]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (result.back() != arr2[i])
        {
            result.push_back(arr2[i]);
        }
        j++;
    }
    while (i < n1)
    {
        if (result.back() != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}