// void merger(int* arr, int s, int mid, int e){
    
//     int* temp = (int*)malloc(sizeof(int) * (e-s+2));
    
//     int i = s;
//     int j = mid+1;
//     int k = 0;
//     while(i <= mid && j <= e){
        
//         if(arr[i] <= arr[j]){
//             temp[k++] = arr[i++]; 
//         }else{
//             temp[k++] = arr[j++];
//         }
//     }
//     while(i <= mid) temp[k++] = arr[i++];
//     while(j <= e) temp[k++] = arr[j++];
    
//     k = 0;
//     int ind = s;
//     while(k < (e-s+1)){
//         arr[ind++] = temp[k++];
//     }
// }

// void merge(int* arr, int s, int e){
    
//     if(s >= e) return;
//     int mid = (s+e)/2;
//     merge(arr, s, mid);
//     merge(arr, mid+1, e);
//     merger(arr, s, mid, e);
// }

int cmp(int *a, int *b){
    return (*(int*)a - *(int*)b);
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    
    int* arr = (int*)malloc(sizeof(int*) * (pointsSize+1));
    for(int i=0; i<pointsSize; i++){
        arr[i] = points[i][0];
    }
    
    // merge(arr, 0, pointsSize-1);
    qsort(arr, pointsSize, sizeof(int), cmp);
    int ans = 0;
    
//     for(int i=0; i<pointsSize; i++){
//         printf("%d ", arr[i]);
//     }
    
    for(int i=1; i<pointsSize; i++){
        if(arr[i] - arr[i-1] > ans){
            ans = arr[i] - arr[i-1];
        }
    }
    return ans;
}