//package pr2calc;
public class SourceExample{

	public int a;
	public int[][] b;
	public String str;

	public SourceExample(){
	    int h,i;

	    this.a = -1;
	    this.b = new int[2][2];

	    for(h=0;h<this.b.length;h++){
	        for(i=0;i<this.b[0].length;i++){
	            this.b[h][i] = -1;
	        }
	    }

	    this.str = "";
	}

	public SourceExample(int value,int[][] value2,String value3){
	    int h,i;

	    this.setA(value);
	    this.b = new int[2][2];
	    setB(value2);
	    this.setStr(value3);
	}

	public void setA(int value){
	    this.a = value;
	}

	public int getA(){
	    return this.a;
	}

	public void setB(int[][] value){
		this.b = value;
	}

	public int[][] getB(){
	    return this.b;
	}

	public void setStr(String value){
	    this.str = value;
	}

	public String getStr(){
	    return this.str;
	}

	public void showAllContentsOfB(){
		int h,i;
		System.out.println();
	    for(h=0;h<this.b.length;h++){
	        for(i=0 ; i<(this.b[0].length)-1 ; i++){
	        	System.out.print(this.b[h][i] + " ,");
	        }
	        System.out.println(this.b[h][i]);
	    }
		System.out.println();
	}

	public static void main(String[] args){
	    SourceExample    ex;
	    int value[][] = {{1,2,3},{4,5,6},{7,8,9}};

	    //ex = new SourceExample();    // SourceExample �N���X�̃I�u�W�F�N�g ex �𐶐�
	    //ex.setA(10);    // ex �I�u�W�F�N�g�̃t�B�[���h this.a �̒l��10�ɕύX�G

	    ex = new SourceExample(3,value,"Hello World");

	    System.out.println("�I�u�W�F�N�g��a�t�B�[���h�̒l��"+ex.getA()+"�ł�");
	    ex.showAllContentsOfB();
	    System.out.println(ex.getStr());

	}

}