/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef __IA_CSS_QUEUE_COMM_H
#define __IA_CSS_QUEUE_COMM_H

#include "type_support.h"
#include "ia_css_circbuf.h"
/*****************************************************************************
 * Queue Public Data Structures
 *****************************************************************************/

/* Queue location specifier */
/* Avoiding enums to save space */
#define IA_CSS_QUEUE_LOC_HOST 0
#define IA_CSS_QUEUE_LOC_SP   1
#define IA_CSS_QUEUE_LOC_ISP  2

/* Queue type specifier */
/* Avoiding enums to save space */
#define IA_CSS_QUEUE_TYPE_LOCAL  0
#define IA_CSS_QUEUE_TYPE_REMOTE 1

/* for DDR Allocated queues,
allocate minimum these many elements.
DDR->SP' DMEM DMA transfer needs 32byte aligned address.
Since each element size is 4 bytes, 8 elements need to be
DMAed to access single element.*/
#define IA_CSS_MIN_ELEM_COUNT    8
#define IA_CSS_DMA_XFER_MASK (IA_CSS_MIN_ELEM_COUNT - 1)

/* Remote Queue object descriptor */
struct ia_css_queue_remote {
	uint32_t cb_desc_addr; /*Circbuf desc address for remote queues*/
	uint32_t cb_elems_addr; /*Circbuf elements addr for remote queue*/
	uint8_t location;    /* Cell location for queue */
	uint8_t proc_id;     /* Processor id for queue access */
};
typedef struct ia_css_queue_remote ia_css_queue_remote_t;


#endif /* __IA_CSS_QUEUE_COMM_H */
