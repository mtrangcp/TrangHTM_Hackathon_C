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
		printf("\n2. In ra gia tri cac phan tu trong mang theo dong (arr[0] = 1, arr[1] = 5 …)");
		printf("\n3. Tim gia tri nho nhat va lon nhat trong mang");
		printf("\n4. In ra tong cua tat ca cac phan tu");
		printf("\n5. Them 1 phan tu vao cuoi mang, phan tu them do nguoi dung nhap");
		printf("\n6. Xoa phan tu tai 1 vi tri cu the( vi tri do nguoi dung nhap)");
		printf("\n7. Sap xep mang theo thu tu giam dan  (Bubble sort)	");
		printf("\n8. Tim kiem phan tu( nguoi dung nhap ) xem co ton tai trong mang hay khong(Linear search)");
		printf("\n9. In ra toan bo so nguyen to trong mang ( neu khong co thi hien thong bao khong co so nguyen to trong mang)");
		printf("\n10. Sap xep mang theo thu tu tang dan  (Selection sort)	");
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
					int max = arr[0], min = arr[0];
					
					for ( int i =0; i< n; i++){
						if ( arr[i] > max ){
							max = arr[i];
						}
						if ( arr[i] < min ){
							min = arr[i];
						}
					}
					printf("\nGia tri lon nhat trong mang: %d", max);
					printf("\nGia tri nho nhat trong mang: %d", min);
				}
				break;
			}
			case 4: {
				if ( check == -1 ){
					printf("\nMang rong, vui long chon cn1 truoc khi chon cn khac!");
				}else{
					printf("\nBan chon 4!");
					int sum = 0;
					for ( int i =0; i< n; i++){
						sum += arr[i];
					}
					printf("\nTong cac phan tu trong mang: %d", sum);
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
					arr[n-1] = num;
					
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
					
					for ( int i =0; i< n; i++){
						for ( int j = 0; j< n-i-1 ; j++){
							if (arr[j] < arr[j+1] ){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
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
					int num, test = -1;
					printf("\nGia tri muon tim: ");
					scanf("%d", &num);
					
					printf("\nPhan tu muon tim o vi tri: ");
					for ( int i =0; i< n; i++){
						if ( arr[i] == num){
							test = 1;
							printf("\t%d", i+1);
						}
					}
					if ( test == -1 ){
						printf("Khong tim thay gia tri muon tim!\n");
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
							printf("\t%d", element[i]);
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
				
					printf("\nMang ban dau: ");
					for ( int i =0; i< n; i++){
						printf("\t%d", arr[i]);
					}
				
					for ( int i = 0; i< n; i++){
						int minIndex = i;
						for ( int j = i+1; j< n; j++){
							if ( arr[j] < arr[minIndex]){
								minIndex = j;
							}
						}
						if ( minIndex != i){
							int temp = arr[minIndex];
							arr[minIndex] = arr[i];
							arr[i] = temp;
						}
					}
				
					printf("\nKq: \t");
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
