class Solution {
    public int minHeightShelves(int[][] libros, int anchoEstante) {
        //Paso#1
        //Se calcula el número total de libros.
        //Se crea un arreglo para realizar programación dinamica de tamaño n+1. 
        //Cada elemento representará la altura mínima para colocar los primeros libros.
        int n = libros.length;
        int[] dp = new int[n + 1];

        //Paso#2
        //La altura inicial siempre va a ser 0
        dp[0] = 0;

        //Paso#3
        //Recorremos todos los libros, iniciando en la posición 1, porque la posición 0 es 0
        for (int i = 1; i <= n; i++) {
            //Paso#4
            // Inicializamos la altura actual como la altura del libro actual, y agregamos
            // la altura actual en el estante que estamos evaluando
            int alturaActual = libros[i - 1][1];
            int anchoActual  = libros[i - 1][0];
            dp[i] = dp[i - 1] + alturaActual; // Si ponemos el libro actual en un nuevo estante

            //Paso#5
            // Iteramos sobre los libros anteriores para ver si podemos colocarlos en el mismo estante
            for (int j = i - 1; j >= 1; j--) {
                //Se actualiza el ancho actual.
                anchoActual += libros[j - 1][0];
                //Si el ancho excede el ancho máximo del estante, se finaliza el bucle, porque pasamos al siguiente libro.
                if (anchoActual > anchoEstante) break;

                //Se actualiza la altura actual si el libro anterior es más alto.
                
                alturaActual = Math.max(alturaActual, libros[j - 1][1]);
                //Se actualiza dp[i] si la nueva aluta de libros resulta menor.
                dp[i] = Math.min(dp[i], dp[j - 1] + alturaActual);
            }
        }

        //Paso#6
        //Se retorna la altura mínima para colocar todos los libros almacenados en dp[n].
        return dp[n];
    }
}

// class Solution {
//     public int minHeightShelves(int[][] books, int shelfWidth) {
//         int[] dp = new int[books.length + 1];
//         dp[books.length] = 0;
//         for (int i = books.length - 1; i >= 0; i--) {
//             int height = books[i][1];
//             int width = books[i][0];
//             dp[i] = height + dp[i + 1];
//             for (int j = i + 1; j < books.length && (width+books[j][0] <= shelfWidth); j++) {
//                 height = Math.max(height, books[j][1]);
//                 width += books[j][0];
//                 dp[i] = Math.min(dp[i], height + dp[j+1]);
//             }
//         }
//         return dp[0];
//     }
// }
