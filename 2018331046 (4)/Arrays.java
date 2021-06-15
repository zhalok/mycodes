public class Arrays
{  
 public static void main(String[] args) {
     int n;
        Scanner input = new Scanner(System.in);
        n=input.nextInt();
        int array1[]= new int[n];
        int array2[]= new int[n];
        for(int i=0;i<n;i++)
        {
            array1[i]=input.nextInt();
            array2[i]=input.nextInt();
        }
        if(Arrays.equals(array1,array2))
            System.out.println("yes");
        Arrays.sort(array1);
        Arrays.sort(array2);
        Arrays.fill(array1,5);
        Arrays.fill(array2,5);
        array1 = Arrays.copyOfRange(array2,0,4);
        System.out.println(array1.toString());
        System.out.println(array2.toString());





    }
}