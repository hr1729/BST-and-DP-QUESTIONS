package com.example.tictacktoe

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity(), View.OnClickListener {
    var play=true
    var turn = 0
    var board1=Array(3){IntArray(3)}
    lateinit var board: Array<Array<Button>>
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
         board =arrayOf(arrayOf(button1,button2,button3),
            arrayOf(button4,button5,button6),
                arrayOf(button7,button8,button9)
        )
        for(i in board){
            for(button in i){
                button.setOnClickListener(this)
            }
        }
        iniate()
        Res1.setOnClickListener{
            iniate()
        }


    }
    private fun iniate(){
        for(i in 0..2){
            for(j in 0..2){
                board1[i][j]=-1
                board[i][j].text=""
                board[i][j].isEnabled=true

            }
        }
    }


    override fun onClick(view: View){
        when(view.id){
            R.id.button1->{
                updateVaue(row=0,column=0,player=play);

            }
            R.id.button2->{
                updateVaue(row=0,column=1,player=play);

            }
            R.id.button3->{
                updateVaue(row=0,column=2,player=play);

            }
            R.id.button4->{
                updateVaue(row=1,column=0,player=play);

            }
            R.id.button5->{
                updateVaue(row=1,column=1,player=play);

            }
            R.id.button6->{
                updateVaue(row=1,column=2,player=play);

            }
            R.id.button7->{
                updateVaue(row=2,column=0,player=play);

            }
            R.id.button8->{
                updateVaue(row=2,column=1,player=play);

            }
            R.id.button9->{
                updateVaue(row=2,column=2, player=play);

            }

        }
        turn+=1
        play=!play

        if(turn==9)
            updateDisplay(text="game draw")
         else if(play)
             updateDisplay(text="Player X turn")
         else
            updateDisplay(text ="Player O Turn")
        checkWinner()

    }
    private fun updateDisplay(text:String){
        tex1.text=text
    }
    private fun checkWinner(){
        for(i in 0..2) {
            if(board1[i][0]== board1[i][1] && board1[i][0]==board1[i][2]){
                if(board1[i][0]==1) {
                    updateDisplay(text = "Player X Winner")
                    break
                }
                else if(board1[i][0]==0){
                    updateDisplay(text = "Player O Winner")
                    break
                }

            }
            if(board1[0][i]== board1[1][i] && board1[0][i]==board1[2][i]){
                if(board1[0][i]==1) {
                    updateDisplay(text = "Player X Winner")
                    break
                }
                else if(board1[0][i]==0){
                    updateDisplay(text = "Player O Winner")
                    break
                }

            }
            if(board1[0][0]== board1[1][1] && board1[0][0]==board1[2][2]){
                if(board1[0][0]==1) {
                    updateDisplay(text = "Player X Winner")
                    break
                }
                else if(board1[0][0]==0){
                    updateDisplay(text = "Player O Winner")
                    break
                }

            }
            if(board1[0][2]== board1[1][1] && board1[0][2]==board1[2][0]){
                if(board1[0][2]==1) {
                    updateDisplay(text = "Player X Winner")
                    break
                }
                else if(board1[0][2]==0){
                    updateDisplay(text = "Player O Winner")
                    break
                }

            }
        }
    }

    private fun updateVaue(row:Int,column:Int,player:Boolean){
        var text=if(player) " X " else "O"
        var value:Int=if(player) 1 else 0
        board[row][column].apply {
            isEnabled=false
            setText(text)
        }
        board1[row][column]=value


    }

}