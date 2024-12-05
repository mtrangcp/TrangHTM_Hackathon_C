#include <stdio.h>

int checkElement( int n ){
	if ( n < 2 ){
		return 0;
	}
	for ( int i = 2; i< n; i++){
		if ( n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int choice, n, check = -1;
	int arr[100];
	
	do{
		printf("\n\n------------Menu--------------------");
		printf("\n1. Nhap so phan tu va gia tri cho mang");
		printf("\n2. In ra gia tri cac phan tu trong mang theo dong (arr[0] = 1, arr[1] = 5 )");
		printf("\n3. Dem so luong phan tu chan le trong mang");
		printf("\n4. Tim gia tri lon thu hai trong mang");
		printf("\n5. Them 1 phan tu vao dau mang, phan tu them do nguoi dung nhap");
		printf("\n6. Xoa phan tu tai 1 vi tri cu the( vi tri do nguoi dung nhap)");
		printf("\n7. Sap xep mang theo thu tu giam dan  (Insertion sort)	");
		printf("\n8. Tim kiem phan tu( nguoi dung nhap ) xem co ton tai trong mang hay khong(Binary search)");
		printf("\n9. In ra toan bo so nguyen to trong mang da duoc binh phuong( neu khong co thi hien thong bao khong co so nguyen to trong mang)");
		printf("\n10. Sap xep mang theo thu tu giam dan  (Bubble sort)	");
		printf("\n11. Thoat");
		printf("\n Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch ( choice){
			case 1: {
				printf("\nBan chon 1!");
				check = 1;
				printf("\nSo phan tu can nhap la(1-50): ");
				scanf("%d", &n);
				
				if ( n<1 || n>50 ){
					printf("\nDu lieu ban nhap khong hop le! Vui long chon lai!");
					break;
				}
				
				for ( int i =0; i< n; i++){
					printf("Nhap phan tu thu %d: ", i+1);
					scanf("%d", &arr[i]);
				}
				
				printf("\nKet qua sau khi nhap: ");
				for ( int i =0; i< n; i++){
					printf("\t%d", arr[i]);
				}
				
				break;
			}
			case 2: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 2!");
					printf("\nCac phan tu trong mang: \n");
					for ( int i =0; i< n; i++){
						printf("\t arr[%d] = %d \n", i,arr[i]);
					}
				}
				
				break;
			}
			case 3: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 3!");
					int countEven  = 0, countOdd = 0;
					
					for ( int i =0; i< n; i++){
						if ( arr[i] % 2 == 0 ){
							countEven++;
						}else{
							countOdd++;
						}
					}
					printf("\nMang co %d so chan, %d so le", countEven, countOdd);
				}
				break;
			}
			case 4: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 4!");
					int newArr[n];
					
					for ( int i =0; i< n; i++){
						newArr[i] = arr[i];
					}
					
					for ( int i =0; i< n; i++){
						for ( int j = 0; j< n-i-1 ; j++){
							if (newArr[j] < newArr[j+1] ){
								int temp = newArr[j];
								newArr[j] = newArr[j+1];
								newArr[j+1] = temp;
							}
						}
					}
					
					printf("\nPhan tu lon thu hai trong mang: %d", newArr[1]);
				}
				break;
			}
			case 5: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 5!");
					int num;
					printf("\nGia tri muon them: ");
					scanf("%d", &num);
					
					n+=1;
					for ( int i = n-1; i >=0 ; i--){
						arr[i] = arr[i-1];
					}
					arr[0] = num;
					
					printf("\nket qua sau khi them: ");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
				}
				break;
			}
			case 6: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 6!");
					int index;
					printf("\nVi tri muon xoa(1-%d): ", n);
					scanf("%d", &index);
				
					if ( index > n  || index < 1){
						printf("\nVui long nhap dung vi tri muon xoa(1-%d) ", n);
						break;
					}
					
					for ( int i = index-1; i < n  ; i++){
						arr[i] = arr[i+1];
					}
					n-=1;
					
					printf("\nket qua sau khi xoa: ");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
					
				}
				break;
			}
			case 7: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 7: Sap xep giam dan!");
					
					for ( int i = 0; i< n; i++){
						int key = arr[i];
						int j = i-1;
						while( j >= 0 && key > arr[j] ){
							arr[j+1] = arr[j];
							j--;
						}
						arr[j+1] = key;
					}
					
					printf("\nket qua sau khi sap xep: ");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
				}
				break;
			}
			case 8: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 8: Tim kiem!");
					int num, start = 0, mid, flag = -1;
					int end = sizeof(arr)/ sizeof(int);
					
					for ( int i = 0; i< n-1; i++){
						for ( int j = 0; j< n-1-i; j++){
							if ( arr[j] > arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
				
					printf("\n\nNhap so muon tim: ");
					scanf("%d", &num);
					
					while( start <= end){
						mid = ( start + end)/2 ;
						if ( arr[mid] == num){
							printf("\nVi tri phan tu muon tim: %d", mid+1);
							flag = 1;
							break;
							
						}else if ( arr[mid] > num){
							end = mid -1;
						}else{
							start = mid+1;
						}
					}
					if ( flag == -1){
						printf("\nKhong tim thay phan tu muon tim!");
					}
				}
				break;
			}
			case 9: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 9!");
					int count = -1, countE = -1;
					
					int element[n];
					for ( int i =0; i< n; i++){
						element[i] = 0;
					}
					
					printf("\nSo nguyen to trong mang: ");
					for ( int i =0; i< n; i++){
						if ( checkElement( arr[i] ) == 1){
							for ( int k = 0; k< n; k++){
								if ( arr[i] == element[k]){
									countE = 1;
									break;
								}
							}
							if ( countE == -1){
								element[i] = arr[i];
							}
							countE = -1;
							count = 1;
						}
					}
					
					for ( int i =0; i< n; i++){
						if ( element[i] != 0 ){
							printf("\t%d - binh phuong: %d \n", element[i], element[i]*element[i] );
						}
					}
					if ( count == -1 ){
						printf("Khong co so nguyen to trong mang!");
					}
				}
				
				break;
			}
			case 10: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 10: Sap xep tang dan (Selection sort)!");
				
					printf("\nMang ban dau: \n");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
				
					for ( int i =0; i< n; i++){
						for ( int j = 0; j< n-i-1 ; j++){
							if (arr[j] < arr[j+1] ){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
				
					printf("\nKq: \n");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
				}
				break;
			}
			case 11: {
				printf("\nBan chon 11: Thoat!");
				break;
			}
			default:{
				printf("\nVui long chon dung Menu(1-11)!");
				break;
			}
		}
		
	}while(choice != 11 );
	
	return 0;
}
