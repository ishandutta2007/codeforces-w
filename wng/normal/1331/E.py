t="""                          + + ++++++ +                          
                      + +++ + + +  + +++++                      
                    +++ +   +   ++ +    +  +                    
                 ++++ + + +++++    ++++ + +++ +                 
                ++      + +     ++++    + + + ++                
              +  ++ +++++ +++ +++ +  + ++   +  + +              
             +++  +  +      + +   ++++  ++ ++ ++ ++             
           ++++++ ++ ++ +++ +++ +++    ++  +  +   +++           
          ++++++++++++    +     +   + ++  ++ ++ +  +++          
         ++++++++++++++++++++ +++++++  ++++  ++++++++++         
        ++++++++++++++++++++++++++++++++++++++++++++++++        
       ++++++++++++++++++++++++++++++++++++++++++++++++++       
       ++++++++++++++++++++++++++++++++++++++++++++++++++       
      ++++++++++++++++++++++++++++++++++++++++++++++++++++      
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++     
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++     
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   
     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++   
       ++++++++++++   +  ++++++++++++++   + + +++++++++++++     
  ++     +++++++++  +   +++++++++++++++ +       ++++++++        
  ++++     +++++   ++ +   +++++++++++++++ ++ ++  + ++       ++  
 +++++++     +   +++  +++  +++++++++++ +  +   ++         ++++++ 
 +++++++++     +  +  ++ ++   +++++++++ ++ +++++  +    +++++++++ 
 ++++++++++++ ++ +++     +++  +++++++   +  +    +++ +++++++++++ 
 +++++++++     +   +++ +++   ++++++++ + +++++ +   +  + ++++++++ 
++++++++++++ +++ +  +  +   +  ++++++  +  +    ++ +++   +++++++++
+++++++++++   +  + ++ +++ +++ ++++ + +++ ++++  +++   + +++++++++
+++++++++++ ++++++ ++++    +  + +    + +  + ++++   +++ +++++++++
+++++++++++     +  +  +++ +++   + + ++ ++ +  +   +  +  +++++++++
++++++++++++ ++ ++++ ++ +++   + +++     ++++ + ++++++ ++++++++++
+++++++++++   +++  +  +   +++ +  +++ ++++  + +++   +   +++++++++
+++++++++++++     ++ +++ ++ +++ ++     +  ++ ++  +   + +++++++++
++++++++++++++ ++ +    + +    + +  + + ++ +   ++ ++ ++++++++++++
++++++++++++    ++++ + + + + ++++ ++ +  + +++  +++   +++++++++++
+++++++++++++ +  +   +++   ++++   +  ++    +  ++   +++++++++++++
++++++++++++++++   +++   + ++ ++ ++ ++  + +++ +  +  ++++++++++++
++++++++++++++++++   + ++++++     +++++++   +   ++++++++++++++++
 ++++++++++++++++  +    +++++ + +++++++++++   +  ++++++++++++++ 
 ++++++++++++++++++++++++++++++    ++++++++++++++++++++++++++++ 
 +++++++++++++++++++++++++++ +  + +++++++++++++++++++++++++++++ 
 +++++++++++++++++++++++++ +   ++++++++++++++++++++++++++++++++ 
  ++++++++++++++++++++++++   +   +++++++++++++++++++++++++++++  
  +++++++  +++++++++++++++++++ +++++++++++++++++++++++++++++++  
   +++++++ + ++++++++++++++++   +++++++++++++++++++++ +++++++   
   +++++++   +   +++++++++++  + +++++++++++ +++++ +    ++++++   
   +++++++ + + +  + +   ++ + ++  + +  + ++   ++     + +++++++   
    ++++++++   ++     +       ++   ++      + +  +++ ++++++++    
     +++++++ +  ++++ ++++ +++  +++    +++ +++++ + +++++++++     
     ++++++++++ +  +  +   + ++++ +++ ++ +     +   +++++++++     
      ++++++++    ++ ++ +    +   + +    +++ +   ++++++++++      
       +++++++++ ++   +++++ ++ + +   + ++   +++++++++++++       
       +++++++++  +++  + +   +++   + +++  +   +++++++++++       
        +++++++++   ++++   +++ ++ ++++ ++++ ++++++++++++        
         +++++++++ ++    + +      +    + ++++++++++++++         
          ++++++++++++ + ++++ ++ ++ + ++  ++++++++++++          
           +++++++++++++    ++++    +    ++++++++++++           
             ++++++++++++++++++++ +++++++++++++++++             
              ++++++++++++++++++++++++++++++++++++              
                ++++++++++++++++++++++++++++++++                
                 ++++++++++++++++++++++++++++++                 
                    ++++++++++++++++++++++++                    
                      ++++++++++++++++++++                      
                          ++++++++++++                          """.split("\n")

i,j=[int(k) for k in input().split(" ")]
print("IN" if t[i][j]=="+" else "OUT")