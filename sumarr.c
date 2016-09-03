
int main(){
    int n,Sum=0,arr_i; 
    scanf("%d",&n);
    int arr[n];
    for(arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
        Sum+=arr[arr_i];
    }
    printf("%d",Sum);
    return 0;
}

