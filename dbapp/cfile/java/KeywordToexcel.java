import java.util.Calendar;
import org.apache.poi.ss.usermodel.CellStyle;
import org.apache.poi.ss.util.Region;
import org.apache.poi.ss.usermodel.Font;
import org.apache.poi.ss.usermodel.IndexedColors;
import org.apache.poi.hssf.record.cf.BorderFormatting;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class KeywordToexcel{
	public static void main(String args[]) throws IOException{
		
		String group_name=args[0];
	    String user_name=args[1];
	    String servic_name=args[2];
	    String sDate=args[3];
	    String key_name=args[4];

		XLSCreate e=new XLSCreate("/datacenter/msa/report/msaexport/keyrecord/keyexport.xls");
        //����
		    Font headfont = e.workbook.createFont();
		    headfont.setFontName("����");
		    headfont.setFontHeightInPoints((short) 22);// �����С
		    headfont.setBoldweight(Font.BOLDWEIGHT_BOLD);// �Ӵ�
		    //����
		    CellStyle headstyle = e.workbook.createCellStyle();
		    headstyle.setFont(headfont);
		    headstyle.setAlignment(CellStyle.ALIGN_CENTER);// ���Ҿ���
		    headstyle.setVerticalAlignment(CellStyle.VERTICAL_CENTER);// ���¾���
		    headstyle.setLocked(true);
		    headstyle.setWrapText(true);// �Զ�����
        //һ����ʽ
		    CellStyle title = e.workbook.createCellStyle();
		    title.setBorderBottom(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    title.setBottomBorderColor(IndexedColors.BLACK.getIndex()); // ���õ�Ԫ��ı߿���ɫ��
		    title.setBorderTop(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    title.setTopBorderColor(IndexedColors.BLACK.getIndex()); // ���õ�Ԫ��ı߿���ɫ��
		    title.setBorderLeft(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    title.setLeftBorderColor(IndexedColors.BLACK.getIndex()); // ���õ�Ԫ��ı߿���ɫ��
		    title.setBorderRight(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    title.setRightBorderColor(IndexedColors.BLACK.getIndex()); // ���õ�Ԫ��ı߿���ɫ

				//����
		    Font columnHeadFont = e.workbook.createFont();
		    columnHeadFont.setFontName("����");
		    columnHeadFont.setFontHeightInPoints((short) 10);
		    columnHeadFont.setBoldweight(Font.BOLDWEIGHT_BOLD);
		    // ��ͷ����ʽ
		    CellStyle columnHeadStyle = e.workbook.createCellStyle();
		    columnHeadStyle.setFont(columnHeadFont);
		    columnHeadStyle.setAlignment(CellStyle.ALIGN_LEFT);// ���Ҿ���
		    columnHeadStyle.setVerticalAlignment(CellStyle.VERTICAL_BOTTOM);// ���¾���
		    columnHeadStyle.setLocked(true);
		    columnHeadStyle.setWrapText(true);
		    
		    columnHeadStyle.setBorderBottom(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    columnHeadStyle.setBorderTop(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    columnHeadStyle.setBorderLeft(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ���壮
		    columnHeadStyle.setBorderRight(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    //С����
		    CellStyle titleStyle = e.workbook.createCellStyle();
		    titleStyle.setFont(columnHeadFont);
		    titleStyle.setAlignment(CellStyle.ALIGN_CENTER);// ���Ҿ���
		    titleStyle.setVerticalAlignment(CellStyle.VERTICAL_CENTER);// ���¾���
		    titleStyle.setLocked(true);
		    titleStyle.setWrapText(true);
		    
		    titleStyle.setBorderBottom(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    titleStyle.setBorderTop(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    titleStyle.setBorderLeft(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ���壮
		    titleStyle.setBorderRight(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
				// ��ͨ��Ԫ����ʽ
			Font font = e.workbook.createFont();
		    font.setFontName("����");
		    font.setFontHeightInPoints((short) 10);
		    CellStyle style = e.workbook.createCellStyle();
		    style.setFont(font);
		    style.setAlignment(CellStyle.ALIGN_LEFT);// ���Ҿ���
		    style.setVerticalAlignment(CellStyle.VERTICAL_BOTTOM);// ���¾���
		    style.setWrapText(true);
		    style.setLeftBorderColor(IndexedColors.BLACK.getIndex());
		    style.setBorderLeft((short) 1);
		    style.setRightBorderColor(IndexedColors.BLACK.getIndex());
		    style.setBorderRight((short)1);
		    style.setBorderLeft(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    style.setBorderRight(BorderFormatting.BORDER_THIN); // ���õ�Ԫ��ı߿�Ϊ����
		    style.setBottomBorderColor(IndexedColors.BLACK.getIndex()); // ���õ�Ԫ��ı߿���ɫ
		    style.setFillForegroundColor(IndexedColors.WHITE.getIndex());// ���õ�Ԫ��ı�����ɫ
		    
	        e.createRow(0,500);//��һ�У������ø߶�
	        e.mergingCell(0,0,0,5);//�ϲ�0��8
	        Region region = new Region((short)0,(short)0,(short)0,(short)5);
	        e.setRegionStyle(region,title);
	        e.setCell(0,"�ؼ����б��ѯ",headstyle);
	        
	        e.createRow(1);//�ڶ���
	        e.mergingCell(1,1,1,5);
	        Region region1 = new Region((short)1,(short)1,(short)1,(short)5);
	        e.setRegionStyle(region1,title);
	        e.setCell(0,"��ѯ����",columnHeadStyle);
	        e.setCell(1,sDate,style);
	        
	        e.createRow(2);//������
	        e.mergingCell(2,2,0,5);
	        Region region2 = new Region((short)2,(short)0,(short)2,(short)5);
	        e.setRegionStyle(region2,title);
	        e.setCell(0,"��������",titleStyle);
	        
	        e.createRow(3);//������
	        e.mergingCell(3,3,1,5);
	        Region region3 = new Region((short)3,(short)1,(short)3,(short)5);
	        e.setRegionStyle(region3,title);
	        e.setCell(0,"��������",columnHeadStyle);
	        e.setCell(1,group_name,style);
	        
	        e.createRow(4);//������
	        e.mergingCell(4,4,1,5);
	        Region region4= new Region((short)4,(short)1,(short)4,(short)5);
	        e.setRegionStyle(region4,title);
	        e.setCell(0,"�û���",columnHeadStyle);
	        e.setCell(1,user_name,style);
	        
	        e.createRow(5);//������
	        e.mergingCell(5,5,1,5);
	        Region region5= new Region((short)5,(short)1,(short)5,(short)5);
	        e.setRegionStyle(region5,title);
	        e.setCell(0,"host�ؼ���",columnHeadStyle);
	        e.setCell(1,servic_name,style);
	        
	        e.createRow(6);//������
	        e.mergingCell(6,6,1,5);
	        Region region6= new Region((short)6,(short)1,(short)6,(short)5);
	        e.setRegionStyle(region6,title);
	        e.setCell(0,"�����ؼ���",columnHeadStyle);
	        e.setCell(1,key_name,style);
	        
	        e.createRow(7);//�ڰ���
	        e.mergingCell(7,7,0,5);
	        Region region7= new Region((short)7,(short)0,(short)7,(short)5);
	        e.setRegionStyle(region7,title);
	        e.setCell(0,"��ѯ���",titleStyle);
	        
	        e.createRow(8);
	        e.setCell(0,"���",columnHeadStyle,100);
	        e.setCell(1,"����",columnHeadStyle,100);
	        e.setCell(2,"�û���",columnHeadStyle,100);
	        e.setCell(3,"������",columnHeadStyle,100);
	        e.setCell(4,"ʱ��",columnHeadStyle,100);
	        e.setCell(5,"�����ؼ���",columnHeadStyle,100);
	        
	        int rownum=0;      
	        BufferedReader reader = null;
	        String line = null;
		    reader = new BufferedReader(new FileReader("/datacenter/msa/report/msaexport/keyrecord/keyexport.csv"));	     
		    while((line=reader.readLine())!=null){
		    	   String item[] = line.split("\\|");//���ַ����ָ����ַ�����
		    	   System.out.println(item.length);
		    	   e.createRow(rownum+9,250);     					
					  for (short cellnum = (short) 0; cellnum < item.length; cellnum++){  
						    e.setCell(cellnum,item[cellnum],style);	
				      }		
					 rownum++;
					 if(rownum==20000) break;			  					  
		  }
		    
		   try {
			e.exportXLS();
		 } catch (Exception e1) {
			e1.printStackTrace();
		}
   }
}