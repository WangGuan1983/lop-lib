using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
namespace UDLib.UI
{
	[RequireComponent(typeof(ParticleSystem))]
	public class CParticleMask : MonoBehaviour
	{
	   public RectMask2D mask;
	   public Material mt;
	   private void Awake()
	   {
		   mt = GetComponent<ParticleSystem>().GetComponent<Renderer>().material;
		   mask = GetComponentInParent<RectMask2D>();
		   // ScrollViewλ�ñ仯ʱ���¼���ü�����

		   var rect = GetComponentInParent<CLoopScrollRect>();

		   rect.onValueChanged.AddListener((e) => { setClip(); });

		   setClip();
	   }

	   void setClip()
	   {
		   Vector3[] wc = new Vector3[4];
		   mask.GetComponent<RectTransform>().GetWorldCorners(wc);        // ����world space�еĵ�����
		   var clipRect = new Vector4(wc[0].x, wc[0].y, wc[2].x, wc[2].y);// ѡȡ���½Ǻ����Ͻ�
		   mt.SetVector("_ClipRect", clipRect);                           // ���òü�����
		   mt.SetFloat("_UseClipRect", 1.0f);                             // �����ü�
	   }
	}
}
