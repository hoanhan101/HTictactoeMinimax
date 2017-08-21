+ ------------ +
|  My Journey  |
+ ------------ +

  The reason I chose to do Tic Tac Toe with AI in the first place was to learn about
  the process of making an AI myself. I was thinking about making a lot of If-then rules
  but then I thought it was not the appropriate way to deal with AI. I did some
  research and found out that Tic Tac Toe AI could be made with Minimax Algorithm.
  I knew it was hard but I gave it a try anyway. That is actually a personality of me that
  I rarely ask for permission and wait to start something I want to do, I just do it and
  learn from mistakes, improve, and keep the feedback loop small so I can constantly move forward.

  I read many websites and watched lots of videos to understand what Minimax Algorithm was.
  This video from a lecture in MIT was a really good intro to Game Theory,
  Minimax and Alpha-beta: https://youtu.be/STjW3eH0Cik.


  I figured out that there were two ways to implement minimax in Tic Tac Toe:
  First was http://neverstopbuilding.com/minimax
  and http://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/

  But I didn't really understand that so I move on the to the second one which
  was to write 3 function: minimax, minMove and maxMove. This way was much clear
  so I used it:
  http://www.progtools.org/games/tutorials/ai_contest/minmax_contest.pdf
  http://www.cplusplus.com/forum/general/118598/
  https://cis.k.hosei.ac.jp/~rhuang/Miccl/AI-2/AI2-L4-2015.pdf

  Each links had some good points so I took a bit from each one to apply to mine.
  It was hard to apply because the program design was so different. The classes design
  in the first place was extremely important because it was a solid foundation to scale
  without breaking the old codes.

  Hence, I had to rewrite the program from the beginning 3 times, deleted a lot of
  unnecessary functions, thought about what my classes would look like and how I
  connected them together to do the thing I wanted it to do. After that,
  I could apply the minimax algorithm.

  Also, I didn't know how to write test code for this project because it had an UI
  so I could debug along the way.

  BUT FINALLY I MADE IT! FIRST AI PROGRAM EVER!!!


+ ----------- +
| UML Diagram |
+ ----------- +
                            + ------------------------------------------ +
                            |                   Board                    |
                            + ------------------------------------------ +
                            | + board[10]: Int                           |
                            + ------------------------------------------ +
                            | <<constructor>> + Board()                  |
                            | + init()                                   |
                            | + showBoard()                              |
                            | + displayOpeningMessage()                  |
                            | + displayInstruction()                     |
                            + ------------------------------------------ +



                            + ------------------------------------------ +
                            |                  Player                    |
                            + ------------------------------------------ +
                            | - playerTurn: Bool                         |
                            + ------------------------------------------ +
                            | <<constructor>> + Player()                 |
                            | + setTurn(turn: Bool)                      |
                            | + isTurn(): Bool                           |
                            + ------------------------------------------ +
                                                   ^
                                                   |
                                                   |
                                                   |
                            + ------------------------------------------- +
                            |                                             |
              + -------------------------- +               + ------------------------- +
              |            Human           |               |             AI            |
              + -------------------------- +               + ------------------------- +
              | <<constructor>> + Human()  |               | <<constructor>> + AI()    |
              + -------------------------- +               + ------------------------- +


                          + --------------------------------------------------- +
                          |                     Controller                      |
                          + --------------------------------------------------- +
                          | + myHuman: Human                                    |
                          | + myAI: AI                                          |
                          | + myBoard: Board                                    |
                          + --------------------------------------------------- +
                          | <<constructor>> + Controller()                      |
                          | <<enum>> state: {PLAYING, OWIN, XWIN, DRAW }        |
                          | + checkState(): Bool                                |
                          | + chooseToGoFirst()                                 |
                          | + createMoveList(board[]: Int, list: Int&): Bool    |
                          | + minimax(): Int                                    |
                          | + minMove(board[]: Int): Int                        |
                          | + maxMove(board[]: Int): Int                        |
                          | + displayResult()                                   |
                          | + play(): Bool                                      |
                          | + playAgain(): Bool                                 |
                          + --------------------------------------------------- +

For more information, please visit my website at https://hoanhan101.github.io/
