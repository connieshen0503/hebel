// Copyright (C) 2013  Hannes Bretschneider

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

// The ceiling function
#define CEIL_DIV(x, y) ((x + y - 1) / y)
#define DIV_UP(x, y) ((y) * CEIL_DIV(x, y))
#define ROW(i, w) ((i)/(w))
#define COLUMN(i, w) ((i)%(w))
#define OUTPUT_TO_INPUT_IDX(idx, iw, ow) (ROW((idx), (ow)) * (iw) + COLUMN((idx), (ow)))
#define PRINT_VAR(var, fmt) if (threadIdx.x == 0 & threadIdx.y == 0) \
    printf("(%d, %d) " #var ": " #fmt "\n", blockIdx.x, blockIdx.y, (var))

typedef char nucleotide_t;

typedef enum {
  DNA_A = 'A',
  DNA_C = 'C',
  DNA_G = 'G',
  DNA_T = 'T',
  DNA_R = 'R',
  DNA_Y = 'Y',
  DNA_N = 'N'
} nucleotide;

// Check if nucleotide nt is letter l
#define CHECK_NT(nt, l) (nt == (nucleotide_t) l)

#define TX threadIdx.x
#define TY threadIdx.y
#define TZ threadIdx.z
#define BX blockIdx.x
#define BY blockIdx.y
#define BZ blockIdx.z
#define BDX blockDim.x
#define BDY blockDim.y
#define BDZ blockDim.z
#define GDX gridDim.x
#define GDY gridDim.y
#define GDZ gridDim.z

#define LIN_THREAD_IDX (TZ * BDY * BDX + TY * BDX + TX)
#define LIN_BLOCK_IDX (BZ * GDY * GDX + BY * GDX + BX)
#define LIN_BLOCK_DIM (BDZ * BDX * BDY)
#define LIN_GRID_DIM (GDZ * GDY * GDX)