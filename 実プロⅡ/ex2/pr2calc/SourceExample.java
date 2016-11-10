package pr2calc;

import java.io.*;

public class SourceExample{

	public int a;
	public int[][] b;
	public String str;

	public SourceExample(){
	    int h,i;

	    this.a = -1;
	    this.b = new int[3][3];

	    for(h=0;h<this.b.length;h++){
	        for(i=0;i<this.b[0].length;i++){
	            this.b[h][i] = -1;
	        }
	    }

	    this.str = "";
	}

	// �t�@�C������̃f�[�^���͂ŕϐ�������������R���X�g���N�^���쐬
    public SourceExample(String fileName){
    	try{
    		loadData(fileName);
    	}catch(IOException e){  System.out.println("�t�@�C������̓��͂Ɏ��s���܂����B");}
    }

	public SourceExample(int value,int[][] value2,String value3){
	    int h,i;

	    this.setA(value);
	    this.b = new int[3][3];
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

	private boolean loadData(String fileName) throws IOException{
		int h,i;
		int row, column;
		BufferedReader fin = new BufferedReader(new FileReader(fileName));
		String inputData;
		String[] inputValue;

		inputData = fin.readLine();
		inputValue = inputData.split("\\s");

		if(inputValue.length != 1)
			return false;
		else{
			this.a = Integer.parseInt(inputValue[0]);
			inputData = fin.readLine();
			inputValue = inputData.split("\\s");

			if(inputValue.length != 2)	// �s�����񐔂̑o�����i�[����Ă��Ȃ����
				return false;
			else{
				row = Integer.parseInt(inputValue[0]);
				column = Integer.parseInt(inputValue[1]);
				this.b = new int[row][column];

				for(h = 0; h<row ; h++){
					inputData = fin.readLine();
					inputValue = inputData.split("\\s");
					for(i = 0;i<column;i++){
						this.b[i][h] = Integer.parseInt(inputValue[i]);
					}
				}

				inputData = fin.readLine();
				this.str = inputData;
			}
		}
		fin.close();
		return true;
	}

	public static void main(String[] args)throws Exception{
	    SourceExample    ex;

	    while(1){
		    String data;
		    BufferdReader in;
		    in = new BufferedReader(new InputStreamReader(System.in));
		    data = in.readLine();
		    if(args.length != 1){
	            System.out.println("�������s�K���ł��B�f�[�^���͗p�̃t�@�C�������ēx�w�肵�ĉ������B");
	            String fn = null;
	            // �L�[�{�[�h����t�@�C��������͂��� �ϐ� fn �ɑ������
	            ex = new SourceExample(fn);
		    }
		    else{
		    	String fn = data;
		    	break;
		    }
	    }
	    ex = new SourceExample(fn);

	    System.out.println("�I�u�W�F�N�g��a�t�B�[���h�̒l��"+ex.getA()+"�ł�");
		System.out.println("");
		ex.showAllContentsOfB();
		System.out.println("");
		System.out.println(ex.getStr());


	}

}