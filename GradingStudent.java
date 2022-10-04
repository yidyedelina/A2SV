import java.util.ArrayList;
import java.util.List;

public class GradingStudent {
    public static List<Integer> gradingStudents(List<Integer> grades) {
        List<Integer> roundedGraded = new ArrayList<>();
        for(Integer li: grades){
            int difference = 5 - (li % 5);
            if(li < 38){
                roundedGraded.add(li);
            }else if(difference == 5){
                roundedGraded.add(li);
            }
            else if(difference < 3){
                roundedGraded.add(li + difference);
            }
            else {
                roundedGraded.add(li);
            }
        }
        return roundedGraded;
    }
}
